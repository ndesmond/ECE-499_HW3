/*

ECE-499 Assignment # 3, part 2:

"Using your micro-controller make one xl-320 servo move from 45 deg to 90 deg with a period of 2 seconds and a second move from 0 to 180 with a period of 1 second."

*/

// Define serial device for dxl bus:
#define DXL_BUS_SERIAL1 1  // Dynamixel on serial 1 (USART1)  - OpenCM9.04

// Dynamixel ID:
#define J_ID0 0
#define J_ID2 2

#define Theta0  0
#define Theta45  155.2 //  45 degrees
#define Theta90  310.3 //  90 degrees
#define Theta180 620.7 // 180 degrees

Dynamixel Dxl(DXL_BUS_SERIAL1);
 
void setup()
{
  // Initialize dynamixel bus:
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3); 
  Dxl.jointMode(J_ID0); //jointMode() is to use position mode 
  Dxl.jointMode(J_ID2); //jointMode() is to use position mode 
}

int toggle = 0;

void loop()
{

  if (toggle == 0)
  {
    /*Turn dynamixel ID 0 to position 45 degrees */
    Dxl.goalPosition(J_ID0, Theta45);
    toggle = -1;
  }
  else
  {
    /*Turn dynamixel ID 0 to position 90 degrees */
    Dxl.goalPosition(J_ID0, Theta90);
    toggle = 0;
  }

  /*Turn dynamixel ID 2 to position 0 degrees */
  Dxl.goalPosition(J_ID2, Theta0);

  // Wait for 1 second (1000 milliseconds)
  delay(1000);

  /*Turn dynamixel ID 2 to position 180 degrees */
  Dxl.goalPosition(J_ID2, Theta180);

  // Wait for 1 second (1000 milliseconds)
  delay(1000);             

}

