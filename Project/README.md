# CS301_2024FALL_Project

## Instructions

### Task 1 Basic Control

#### Commands:

 -   ONA:	FORWARD
 -   ONB:    BACKWARD
 -   ONC:    TURN LEFT
 -   OND:    TURN RIGHT
 -   ONE:     LEFT
 -   ONF:     RIGHT
 -   STP:      STOP
 -   PAT:      It is a hint: Enter PATH DESIGN mode
 -   BLO:     It is a hint:  Enter BLOCK  DETECTION mode

### Task 2 Ultrasonic Detection

Return "D 1.41"

Return "B 1"

#### Notice:

- #### **No commands** from STM32 Mini to the car

- #### **Distance information**  and  **block information** needs to be transmitted from the car to STM32 Mini

### Task 3 Routing

#### Commands:  T3 Path[16]

- Header: T3

- Payload: path[16]

- Example: T3 11121314151617171717171717171717

- 参数定义：T3  \<point1\> \<point2\> \<point3\> ... \<pointn\>

- 其中point1为起始点，最后一个不为16的值为终止点

- 网格定义如下：

- ```
  -------------
  |0 |1 |2 |3 |
  -------------
  |4 |5 |6 |7 |
  -------------
  |8 |9 |10|11|
  -------------
  |12|13|14|15|
  -------------
  ```

  

### Task 4 Environmental Detection

#### Commands: T4  StartPoint  EndPoint MaxBlock

- Header: T4

- Payload: \<start point\> \<end point\> <max_block>

- Example: T4 5 12 3

- 参数定义：T4 <start point\> \<end point\> <max_block>

- 网格定义参考task3内容

  



