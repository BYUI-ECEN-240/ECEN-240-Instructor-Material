**ECEN 240 Lab 6 - ALU**

**(Vivado and SystemVerilog Instructions)**

> 1\. Download the Lab6\_ALU.sv file from canvas and place on your
> desktop. You will use this momentarily.
>
> 2\. Start Vivado and Select "Create Project"

![](media/img1.png)

> 3\. Type the project name as "Lab6\_ALU" and select "Next"

![](media/img2.png)

> 4\. Select RTL Project and then "Next"

![](media/img3.png)

5\. Select "Add Files" and navigate to the "Lab6\_ALU.sv" file you
downloaded from the "Lab6" Canvas module. Click on the file and select
OK.

![](media/img4.png)

6\. Skip the "Add Constraints" option and just select "Next"

7\. Configure the project with the correct FPGA filter Settings:

-   Family: Artix-7.

-   Package: cpg236

-   Speed: -1

> 8\. Select "xc7a35tcpg236-1" and then "Next".
>
> ![](media/img5.png)
>
> 9\. To Create the project, select "Finish".
>
> ![](media/img6.png)
>
> 10\. Open the "Lab6\_ALU.sv" within Vivado file by clicking on
> "Lab6\_ALU" in the Sources window.

![Graphical user interface, text, application, email Description
automatically generated](media/img7.png)

> 11\. There are six modules within this file, Lab6\_ALU, ADD4, AND4,
> OR4, XOR4, and MUX4bit\_4to1. You will need to complete all six of
> these modules:

-   Lab6\_ALU is the top level. All other modules are "placed" or
    "instantiated" in this module. Each of the modules are wired
    together using the structural coding style of SystemVerilog. This
    module also has ports that connect to the switches, pushbuttons and
    LEDs on the Basys3 board.

-   ADD4, AND4, OR4, XOR4 each have one assign statement. For example,
    to perform the add function in the "ADD4" module, type:\
    assign out = A + B;

-   MUX4bit\_4to1 will be implemented with three, 2to1 four-bit
    multiplexers.

  |S\[1:0\]  | Function|
  |:--------:|:-------:|
  |   00     |   XOR   |
  |   01     |   AND   |
  |   10     |    OR   |
  |   11     |   ADD   |

12\. Open the elaborated design (side menu). Once this is done, click on
the schematic symbol on the side menu (under RTL ANALYSIS) or at the top
of the Vivado screen.

![](media/img8.png)

13\. You will see a schematic diagram of the synthesized design. To view
the various modules of your part of the design, click on the "+" of each
of the modules to expand their views. You should be able to see your
elaborated schematic.

![](media/img9.png)

14\. Tell Vivado which pins to use on the FPGA chip. Click on the blue
"14 I/O Ports" at the top of the schematic menu. Type the following
information into the I/O Ports list. This tells Vivado how to map the
signal to the switches, seven segment display, and the clocks. You also
need to tell Vivado to use 3.3V by selecting the "LVCMOS33" for the I/O
Std of each of these signals (to see how these pin assignments were
made, look at the last figure in this document).

![](media/img10.png)

15\. Now run the synthesis step (side menu). You will be prompted to
save the configuration file (constraint file). Call it "Lab6\_ALU".

![](media/img11.png)

16\. After successfully running Synthesis, select "Run Implementation"
and open the implemented design. Open the schematic of the implemented
design. You will see that the implemented design no longer shows basic
function of each module. Instead, it shows that Vivado implemented your
design with several small ROMs or LUTs (Look UP Tables).

![](media/img12.png)

17\. Select "Generate Bitstream" from the bottom of the left menu. This
is turning your design into a file that can be dumped into the FPGA. It
can take a while to generate the bitstream. You can follow the progress
by watching top right of the Vivado window.

18\. Connect the Basys3 to the computer using the USB cable, and turn on
the Basys3 power switch.

19\. Select "Open Hardware Manager" from the bottom of the left menu,
and select "Open Target", then "Auto Connect". Once the computer has
connected to the Basys3, you are ready to dump the configuration data
into the FPGA. Select "Program Device".

![](media/img13.png)

You are now running the ALU on the Basys3!

-   Use the four switches on the far left for your "A" input number

-   Use the four switches on the far right for your "B" input number

-   Use the left pushbutton as the "S\[1\]" input

-   Use the right pushbutton as the "S\[0\]" input

-   View the output on the middle four LEDs (above the switches)

![](media/img14.png)