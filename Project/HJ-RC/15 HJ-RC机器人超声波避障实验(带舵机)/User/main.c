//#include "stm32f10x.h"
//#include "delay.h"
//#include "motor.h"
//#include "keysacn.h"
//#include "IRSEARCH.h"
//#include "IRAvoid.h"
//#include "usart.h"
//#include "UltrasonicWave.h"
//#include "timer.h"
//#include "Server.h"

//// 超声波转头函数
//int front_detection()
//{

////HJduino_brake(0);
//	SetJointAngle(90);
//	delay_ms(100);
//	return UltrasonicWave_StartMeasure();
//}
//int left_detection()
//{

////	HJduino_brake(0);
//	SetJointAngle(175);
//	delay_ms(300);
//	return UltrasonicWave_StartMeasure();
//}
//int right_detection()
//{

////	HJduino_brake(0);
//	SetJointAngle(5);
//	delay_ms(300);
//	return UltrasonicWave_StartMeasure();
//}
// int main(void)
// {	
//   int Q_temp,L_temp,R_temp;
//	 delay_init();
//	 KEY_Init();
//	 IRSearchInit();
//	 IRAvoidInit();
//   Timerx_Init(5000,7199);                //10Khz的计数频率，计数到5000为500ms 
//	 UltrasonicWave_Configuration();        //对超声波模块初始化
//	 uart_init(115200);
//	 TIM4_PWM_Init(7199,0);                 //初始化PWM
//	 TIM5_PWM_Init(9999,143);               //不分频，PWM频率=72*10^6/(9999+1)/(143+1)=50Hz	 
//	 HJduino_brake(500);
//	 keysacn();		
//	while(1)
//	{  		
//	//	Q_temp = front_detection();
//	//  printf("测到的距离值为：%d\n",Q_temp);
//		Q_temp = front_detection();
//		if(Q_temp<60 && Q_temp>0) //测量距离值	
//		{
//			HJduino_brake(500);		
//			HJduino_back(60,500);	
//			HJduino_brake(1000);	
//			
//			L_temp=left_detection();//测量左边障碍物的距离值
//			delay_ms(500);
//			R_temp=right_detection();//测量右边障碍物的距离值
//			delay_ms(500);
//			
//			if((L_temp < 60 ) &&( R_temp < 60 ))//当左右两侧均有障碍物靠的比较近
//			{
//				HJduino_Spin_Left(60,1000);
//			}				
//      else if(L_temp > R_temp)
//			{
//				HJduino_Left(60,1000);
//				HJduino_brake(500);
//			}	
//      else
//			{
//				HJduino_Right(60,1000);
//				HJduino_brake(500);					
//			}							
//		}	
//		else
//		{
//			HJduino_run(60,10);
//		}
//	}
// }



//     char buffer[50]; // 用于存储要发送的数据

//    // 构造距离信息 "D <distance>"
//    snprintf(buffer, sizeof(buffer), "D %.2f\n", distance);
//    u2_printf((uint8_t *)buffer);
           // delay_ms(50);


//    // 构造障碍物信息 "B <block>"
//    snprintf(buffer, sizeof(buffer), "B %d\n", block);
//    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)buffer, strlen(buffer));
 
 

#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
#include "usart.h"
#include "usart2.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "UltrasonicWave.h"
#include "timer.h"
#include "Server.h"
#include "keysacn.h"
#include "IRSEARCH.h"
#define N 4
#define INF 10000

/*
void HJduino_run(int speed,int time);       //前进函数
void HJduino_brake(int time);               //刹车函数
void HJduino_Left(int speed,int time);      //左转函数
void HJduino_Spin_Left(int speed,int time); //左旋转函数
void HJduino_Right(int speed,int time);     //右转函数
void HJduino_Spin_Right(int speed,int time);//右旋转函数
void HJduino_back(int speed,int time);      //后退函数

*/
int thisX = -1;//x代表二维数组中的第一维，在坐标中由上往下递增
int thisY = -1;//y代表二维数组中的第二维，在坐标中由左往右递增，
int nextX = -1;
int nextY = -1;
int nextDirection = 0;
int thisDirection = 0;//当x代表二维数组中的第一维，在坐标中由上往下递增，此处表示方向的变量由0至3分别代表右、下、左、上


int ob_x[]={-1,-1,-1,-1,-1,-1,-1};
int ob_y[]={-1,-1,-1,-1,-1,-1,-1};
int ob_count=0;
int Max_count=3;//这个变量是否可以设计成由上位机传输给小车
int final_x=-1;
int final_y=-1;
int count[4][4]={
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}

};

//这里初始化了一个二维数组，当小车探测到前方障碍物时，就会给这个数组中标1
int grid[N][N] = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
};

//下面三个函数是小车例程中自带的，暂时没有用上
	
// 超声波转头函数
int front_detection()
{

//HJduino_brake(0);
	SetJointAngle(80);
	delay_ms(100);
	return UltrasonicWave_StartMeasure();
}
int left_detection()
{

//	HJduino_brake(0);
	SetJointAngle(175);
	delay_ms(300);
	return UltrasonicWave_StartMeasure();
}
int right_detection()
{

//	HJduino_brake(0);
	SetJointAngle(5);
	delay_ms(300);
	return UltrasonicWave_StartMeasure();
}

//这个函数是我最初写的，测试完能用，就没再改了，主要功能是小车在行走的过程中探测障碍物，如果没有障碍物，就成功前进80cm，反之则退回原处
void task3_go(){
	int time = 0;

	while(1){
			HJduino_run(50,10);
			time+=10;
		
		//未遇到障碍，成功前进80cm
		if(time>=3000){
			break;
		}
	

	}
		HJduino_brake(1000);


}
  void moveForward(){
	int time = 0;
	int Q_temp;
//struct	Grid front = *getFrontGrid();
	
	while(1){
		Q_temp = UltrasonicWave_StartMeasure();
		//遇到障碍
		if(Q_temp <= 150 && Q_temp >= 0){
			HJduino_brake(500);
			while(time > 0 && time < 4000){
				 HJduino_back(44,10);//
				 time-=10;
			 }
			break;
		}
		HJduino_run(50,10);
		time+=10;
		
		//未遇到障碍，成功前进80cm
		if(time>=3800){
			break;
		}
	}
	HJduino_brake(1000);
}

//这个函数由moveForward()改写，小车前进的同时探测障碍物，有障碍物则返回-1，同时立即退回远处，反之则返回1，再在行走80cm之后退回原处
int forwardDetect(){
	int time = 0;
	int Q_temp;
	int a=0;
	while(1){
		Q_temp = UltrasonicWave_StartMeasure();
		//遇到障碍
		if(Q_temp <= 150 && Q_temp >= 0){
			HJduino_brake(500);
			while(time > 0 && time < 4000){
				 HJduino_back(44,10);
				 time-=10;
			 }
			HJduino_brake(1000);
			 a=			 -1;
			 return a;
		}
		HJduino_run(50,10);
		time+=10;
		
		//未遇到障碍，退回原处
		if(time>=3800){
			HJduino_brake(500);
			while(time > 0 && time < 4000){
				 HJduino_back(44,10);
				 time-=10;
			 }
			//此处加入将新位置设为旧位置子节点的代码
			break;
		}
	}
	HJduino_brake(1000);
	a=1;
	return a;
}


//这两个转向函数可以恰好使小车原地旋转90度
void turnRight(){
	HJduino_brake(500);
	HJduino_Spin_Right(57,650);
	HJduino_brake(500);
}
void turnLeft(){
	HJduino_brake(500);
	HJduino_Spin_Left(57,650);
	HJduino_brake(500);
}
void turn(){
	if(nextX - thisX == 0 && nextY - thisY == 1){
		nextDirection = 0;
	}else if(nextX - thisX == 1 && nextY - thisY == 0){
		nextDirection = 1;
	}else if(nextX - thisX == 0 && nextY - thisY == -1){
		nextDirection = 2;
	}else if(nextX - thisX == -1 && nextY - thisY == 0){
		nextDirection = 3;
	}
	if(nextDirection > thisDirection){
		int temp = nextDirection - thisDirection;
		switch(temp){
			case 1: turnRight(); break;
			case 2: turnRight();turnRight(); break;
			case 3: turnLeft(); break;
		}
	}else if(nextDirection < thisDirection){
		int temp = thisDirection - nextDirection;
		switch(temp){
			case 1: turnLeft(); break;
			case 2: turnRight();turnRight(); break;
			case 3: turnRight(); break;
		}
	}
	thisDirection = nextDirection;
}

//这个函数只能在当前位置与下一个位置不同的时候移动到下一个位置
void moveToPoint(){
	turn();
	moveForward();
	thisX = nextX;
	thisY = nextY;
}


//下面是自动由给定的点走到终点的代码
// 四个方向：上、下、左、右
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int is_valid(int x,int y){
    return x>=0&&x<N&&y>=0&&y<N;
}


typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pt;
    int dist;
} QueueNode;

typedef struct {
    QueueNode* data;
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->data = (QueueNode*)malloc(N * N * sizeof(QueueNode));
    q->front = q->rear = 0;
}
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, QueueNode node) {
    q->data[q->rear++] = node;
}

QueueNode dequeue(Queue* q) {
    return q->data[q->front++];
}

int isValid(int x, int y, int grid[N][N], int visited[N][N]) {
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] != 1 && !visited[x][y];
}

int bfs(int grid[N][N], Point start, Point end, int prev[N][N]) {
    int visited[N][N] = {0};
    Queue q;
    initQueue(&q);
    enqueue(&q, (QueueNode){start, 0});
    visited[start.x][start.y] = 1;

    while (!isEmpty(&q)) {
        QueueNode current = dequeue(&q);

        // 如果到达终点，跳出循环
        if (current.pt.x == end.x && current.pt.y == end.y) {
            return current.dist;
        }

        for (int i = 0; i < 4; i++) {
            int newX = current.pt.x + dx[i];
            int newY = current.pt.y + dy[i];
            if (isValid(newX, newY, grid, visited)) {
                visited[newX][newY] = 1;
                prev[newX][newY] = current.pt.x * N + current.pt.y; // 存储当前点的前驱节点
                enqueue(&q, (QueueNode){{newX, newY}, current.dist + 1});
            }
        }
    }
    return -1; // 如果没有找到路径
}
int printPath(Point start, Point end, int prev[N][N], Point path[N * N]) {
    int pathLen = 0;
    int x = end.x, y = end.y;

    // 回溯路径
    while (x != start.x || y != start.y) {
        path[pathLen++] = (Point){x, y};
        int prevIndex = prev[x][y];
        x = prevIndex / N;
        y = prevIndex % N;
    }
    path[pathLen++] = start; // 添加起点

    // 逆序打印路径
    for (int i = pathLen - 1; i >= 0; i--) {
        if (i == pathLen - 1){
					thisX = path[i].x;
					nextX = path[i].x;
					thisY = path[i].y;
					nextY = path[i].y;
            printf("(%d, %d)", path[i].x, path[i].y);
				}
        else{
					nextX = path[i].x;
					nextY = path[i].y;
            printf(" -> (%d, %d)", path[i].x, path[i].y);
					
				moveToPoint();
				}
    }
    printf("\n");

    return pathLen;
}

//这是在当前坐标，探测四周方格的函数
void find_obstacle(int x,int y){
	  thisX = x;
	  thisY = y;
    printf("current x=%d,y=%d\n",x,y);
    if(ob_count>=Max_count){
        final_x=x;
        final_y=y;
        return;
    }
		//对走过的小方格count+2，对于没走过，仅仅探测过的方格count+1，以示区分
    count[x][y]+=2;
    for (int i = 0; i < N; ++i) {
        int next_x=x+dx[i];
        int next_y=y+dy[i];
			//如果该方格有效、从未经过并且没有障碍，则探测这一方格
        if(is_valid(next_x,next_y) && count[next_x][next_y]==0 && grid[next_x][next_y]==0 ){
					nextX = next_x;
					nextY = next_y;
					turn();
					int temp = forwardDetect();
					//若小车探测到障碍物，将其与已知障碍物坐标比较，防止重复标记
            if(temp == -1){
							
							forwardDetect();//这行代码很奇怪，因为实际测试的时候发现探测到障碍物之后，下一次执行forwardDetect()或者moveForward()会失效，所以就加了这么一行，在实际运行的过程中，小车并不会前进
                int flag=0;
								grid[next_x][next_y]=1;
                for (int j = 0; j < ob_count; ++j) {
                    if(next_x==ob_x[j]&&next_y==ob_y[j]){
                        flag=1;
                    }
                }
                if(flag==1){
                    continue;
                }
								GPIO_ResetBits(GPIOA,GPIO_Pin_8); //????
								delay_ms(200);

								GPIO_SetBits(GPIOA,GPIO_Pin_8); //???
								int xx=next_x;
								int yy=next_y;
								char blockCommand[10]; // ?????????

								xx=xx*4+yy;
								snprintf(blockCommand, sizeof(blockCommand), "B %02d", xx);
								u2_printf(blockCommand);

                ob_x[ob_count]=next_x;ob_y[ob_count]=next_y;
                ob_count++;//这里有个疑问，由于每个格子判定是否大于maxcount只有一次，但一个格子要探测三个方向，如果不止一个方向有障碍物，这里obcount是有可能大于maxcount的
            }else 
						
						
						{						
							count[next_x][next_y]+=1;
							/*int angle=10;
							
							int Q_temp = UltrasonicWave_StartMeasure();
							if(thisDirection==0){
								
							}
							else if(thisDirection==1){
							}
							else if(thisDirection==2){
							}
							else if(thisDirection==3){
							}
							for(int i=0;i<3;i++){
								SetJointAngle(angle);
								angle+=10;
								
								if(Q_temp<500){
									int flag=0;
								grid[next_x][next_y]=1;
                for (int j = 0; j < ob_count; ++j) {
                    if(next_x==ob_x[j]&&next_y==ob_y[j]){
                        flag=1;
                    }
                }
                if(flag==1){
                    continue;
                }
								GPIO_ResetBits(GPIOA,GPIO_Pin_8); //????
								delay_ms(200);

								GPIO_SetBits(GPIOA,GPIO_Pin_8); //???
								int xx=next_x;
								int yy=next_y;
								char blockCommand[10]; // ?????????

								xx=xx*4+yy;
								snprintf(blockCommand, sizeof(blockCommand), "B %02d", xx);
								u2_printf(blockCommand);

                ob_x[ob_count]=next_x;ob_y[ob_count]=next_y;
                ob_count++;
								
								}
								
							}
							angle=120;
							for(int i=0;i<3;i++){
								SetJointAngle(angle);
								

														angle+=10;
							
							}*/
						
						}
						
					
        }
    }
    int up_x=x-1;int up_y=y;
    int down_x=x+1;int down_y=y;
    int left_x=x;int left_y=y-1;
    int right_x=x;int right_y=y+1;
    int up_value = 1000000, down_value = 1000000, left_value = 1000000, right_value = 1000000;
    if(is_valid(up_x,up_y)&&grid[up_x][up_y]!=1){
        up_value=count[up_x][up_y];
    }
    if(is_valid(down_x,down_y)&&grid[down_x][down_y]!=1){
        down_value=count[down_x][down_y];
    }
    if(is_valid(left_x,left_y)&&grid[left_x][left_y]!=1){
        left_value=count[left_x][left_y];
    }
    if(is_valid(right_x,right_y)&&grid[right_x][right_y]!=1){
        right_value=count[right_x][right_y];
    }
    int arr[4]={up_value,right_value,down_value,left_value};
    int min=200000000;
    int ss=5;
    for (int i = 0; i < 4; ++i) {
        if(arr[i]<min){
            ss=i;
            min=arr[i];
        }
    }
		if(ob_count>=Max_count){
        final_x=x;
        final_y=y;
        return;
    }
    if(ss==0){
			nextX = up_x;
			nextY = up_y;
			moveToPoint();//在决定下次行走的方向后，移动到相应的点
        find_obstacle(up_x,up_y);
    }
    else if(ss==1){
			nextX = right_x;
			nextY = right_y;
			moveToPoint();
        find_obstacle(right_x,right_y);
    }
    else if(ss==2){
			nextX = down_x;
			nextY = down_y;
			moveToPoint();
        find_obstacle(down_x,down_y);
    }
    else if(ss==3){
			nextX = left_x;
			nextY = left_y;
			moveToPoint();
        find_obstacle(left_x,left_y);
    }


}

 int main(void)
 {	
	 GPIO_InitTypeDef  GPIO_InitStructure;
     
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);     //??PA????
    
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;                       //FM-->PA.8 ????
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;           //????
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;          //IO????50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);                          //?????????GPIOA.8
  GPIO_SetBits(GPIOA,GPIO_Pin_8);                                    //PA.8 ??? ???
	 u8 reclen=0;
	 delay_init();
	 TIM4_PWM_Init(7199,0);  //初始化PWM
	 uart_init(9600);
	 USART2_Init(9600);	 
	 HJduino_brake(500);
	 	 TIM5_PWM_Init(9999,143);               //不分频，PWM频率=72*10^6/(9999+1)/(143+1)=50Hz	 

	 	UltrasonicWave_Configuration();               //?????????
Timerx_Init(5000,7199); 
	 while(1)
		{  		
		if (USART2_RX_STA & 0X8000) // 接收到一次数据了
		{
    reclen = USART2_RX_STA & 0X7FFF; // 得到数据长度
    USART2_RX_BUF[reclen] = 0;       // 加入结束符
    printf("USART2_RX_BUF: %s\n", USART2_RX_BUF);
    printf("reclen: %d\n", reclen);
    if (reclen >= 2) // 检查长度是否足够匹配前三个字符
    {			SetJointAngle(80);

        if (strncmp((const char *)USART2_RX_BUF, "ONA", 3) == 0)
        {		
						HJduino_run(80, 100);
           delay_ms(100);
           HJduino_brake(100);
						int Q_temp = UltrasonicWave_StartMeasure();
						char outputStr[32]; // ??????????????????
						sprintf(outputStr, "distance: %d mm", Q_temp);
						u2_printf(outputStr);
            
        }
        else if (strncmp((const char *)USART2_RX_BUF, "ONB", 3) == 0)
        {
            u2_printf("go back!");
            HJduino_back(80, 100);
           delay_ms(100);
            HJduino_brake(100);
        }
        else if (strncmp((const char *)USART2_RX_BUF, "OND", 3) == 0)
        {
            u2_printf("go right!");
            HJduino_Right(80, 100);
            delay_ms(100);
            HJduino_brake(100);
        }
        else if (strncmp((const char *)USART2_RX_BUF, "ONC", 3) == 0)
        {
            u2_printf("go left!");
            HJduino_Left(80, 100);
            delay_ms(100);
            HJduino_brake(100);
        }else if(strncmp((const char *)USART2_RX_BUF, "ONE", 3) == 0){
					u2_printf("left!");
            HJduino_HJ_ZE_L(80, 100);
            delay_ms(100);
            HJduino_brake(100);
						//LEFT FUNCTION
				}else if(strncmp((const char *)USART2_RX_BUF, "ONF", 3) == 0){
					u2_printf("go left!");
            HJduino_HJ_ZE_R(80, 100);
            delay_ms(100);
            HJduino_brake(100);
					  //RIGHT FUNCTION
				}else if(strncmp((const char *)USART2_RX_BUF, "FFF", 3) == 0){
						u2_printf("F");
						delay_ms(100);
				}
				else if(strncmp((const char *)USART2_RX_BUF, "T3", 2) == 0){ 
					           // HJduino_HJ_ZE_R(80, 100);

					Point path[N * N];
					uint8_t receivedPath[16];
          memcpy(receivedPath, USART2_RX_BUF + 2, 16); 
					int start_x=receivedPath[0]/4;int start_y=receivedPath[0]%4;
				//	int start_x=3;int start_y=0;
					thisX=start_x;thisY=start_y;
					//char receivedPathStr[2]; // ????????? + '\0'
				//	u2_printf((char *)USART2_RX_BUF);
				//	u2_printf((char *)USART2_RX_BUF);
				//	int end=0receivedPath
						
						//receivedPath[4]=17;
						//receivedPath[1]=13;
						//receivedPath[2]=9;
						//receivedPath[3]=10;
			//		int end_x=receivedPath[end-1]/4;int end_y=receivedPath[end-1]%4;
					for(int i=1;i<16;i++){
						if(receivedPath[i]==17){
							break;
						}
						
						
						nextX=receivedPath[i]/4;
						nextY=receivedPath[i]%4;
						turn();
					//	moveForward();
						task3_go();
						/*HJduino_run(80, 100);
            delay_ms(100);    
            HJduino_brake(100);
						delay_ms(1000);		*/
						thisX = nextX;
						thisY = nextY;
					}
					
					
					thisX=nextX;
					thisY=nextY;
					nextDirection = 0;
					turn();
					
					 u2_printf("finish routing");
						//Path Routing
				}else if(strncmp((const char *)USART2_RX_BUF, "T4", 2) == 0){
						int s, e,block_cnt; // ???????? s ? e
    if (sscanf((const char *)USART2_RX_BUF, "T4 %d %d %d", &s, &e,&block_cnt) == 3) {
        //u2_printf("s=%d, e=%d\n", s, e);
				Max_count=block_cnt;
					int start_x=s/4;
				int start_y=s%4;
				find_obstacle(start_x,start_y);
			
			int prev[N][N];
			for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            prev[i][j] = -1; // ???????
        }
    }	
			Point start={final_x,final_y};
			Point end={e/4,e%4};
			int result=bfs(grid,start,end,prev);
			if(result==-1){
				printf("no result\n");
			}
			else{
			
			Point path[N*N];
				int a=printPath(start,end,prev,path);
			}
			nextDirection = 0;
					turn();
								 u2_printf("finish searching");

			//************************ 重新开始
			ob_count=0;
			for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        grid[i][j] = 0;count[i][j]=0;
    }
}



        // ????????
        // Environmental Detection
    }
					//Environmental Detection
				}
				
        else if (strncmp((const char *)USART2_RX_BUF, "ONF", 3) == 0 ||
                 strncmp((const char *)USART2_RX_BUF, "ONE", 3) == 0 ||
                 strncmp((const char *)USART2_RX_BUF, "STP", 3) == 0 ||
                 strncmp((const char *)USART2_RX_BUF, "PAT", 3) == 0)
        {
            u2_printf("Stop!");
            HJduino_brake(100);
        }
    }

    USART2_RX_STA = 0; // 清除接收标志
		}
 }
}
