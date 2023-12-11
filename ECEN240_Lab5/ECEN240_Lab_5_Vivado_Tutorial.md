# ECEN 240 Lab 5 Vivado Tutorial**

1. Download the Lab5\_RR.sv file from canvas and place on your
desktop. You will use this in step 5.

2. Start Vivado and Select "Create Project"

![](media/vv1.png){width="4.408952318460193in" height="3.725in"}

3. Type the project name as "Lab5\_RR" and select "Next"

![](media/vv2.png){width="4.358333333333333in"
height="2.5968066491688537in"}

4. Select RTL Project and then "Next"

![](media/vv3.png){width="5.103478783902013in" height="2.35in"}

5. Select "Add Files" and navigate to the "Lab5\_RR.sv" file you downloaded from the "Lab5" Canvas module. Click on the file and select OK.

![](media/vv4.png){width="5.080232939632546in"
height="3.558333333333333in"}

6. Skip the "Add Constraints" option and just select "Next"

7. There are too many FPGA's to choose from! You need to configure the project with the correct FPGA filter Settings:

- Family: Artix-7.
- Package: cpg236
- Speed: -1

8. Now you can easily find and select "xc7a35tcpg236-1" and then
"Next".

![](media/vv5.png){width="4.958333333333333in"
> height="3.4734798775153104in"}

9. To Create the project, select "Finish".

![](media/vv6.png){width="4.930423228346457in" height="3.475in"}

10. Open the "Lab5\_RR.sv" within Vivado file by clicking on
"Lab5\_RR\_top" in the Sources window.

![](media/vv7.png){width="5.0in" height="3.0037390638670165in"}

11. There are 3 modules within this file, Lab5\_RR\_top, Lab5\_RR,
and clk\_gen. You will only edit Lab5\_RR:

-   Observe that the input ports and the output ports that are listed at
    the top of the Lab5\_RR module. These are the signals you will "pass
    in" and "pass out" of the module.

-   Observe that there are two "not" gates, six "and" gates, and two
    "or" gates. Your objective is to add the signal names to each of the
    gates.

    -   Start by naming all the internal wires that are not connected to
        a port. Use names that make sense, like:\
        \
        not (Leftb, Left)\
        and (SR, Stop, Right);\
        \
        where "Leftb" is the inverted "Left" signal and "SR" is the
        "and" of Stop and Right.

    -   After you have completed the circuit description, declare all
        the new signals (like "SR"). Put these declarations between the
        ports and the logic gates:\
        \
        logic Leftb, SR, ...

> 12\. Click on "Run Synthesis" on the side menu. Wait for the synthesis
> to complete. This can take a while.

![](media/vv8.png){width="2.8962379702537184in"
height="3.021255468066492in"}

> 13\. If there were no errors, open the elaborated design (side menu),
> and click on the schematic symbol at the top of the Vivado screen.

![](media/vv9.png){width="4.938188976377953in"
height="0.7605227471566054in"}

> 14\. You will see a schematic diagram of the elaborated design. To
> open your part of the design, click on the "+" sign in the box labeled
> "Lab5\_RR". You should be able to see how Vivado interprets your
> SystemVerilog code.

![](media/vv10.png){width="6.5in" height="3.9340277777777777in"}

> 15\. We need to tell Vivado which pins to use on the FPGA chip. Click
> on the blue "16 I/O Ports" at the top of the schematic menu. Type the
> following information into the I/O Ports list. This tells Vivado how
> to map the signal to the switches, seven segment display, and the
> clocks. It also tells Vivado to use 3.3V by selecting the "LVCMOS33"
> for the I/O Std of each of these signals.

![](media/vv11.png){width="6.5in" height="2.7111111111111112in"}

> 16\. Now re-run the synthesis. You will be prompted to save the
> configuration file (constraint file). Call it "Lab5\_RR".

![](media/vv12.png){width="3.4833333333333334in"
height="3.5542771216097986in"}

17\. After re-running Synthesis, select "Run Implementation" and open
the implemented design. Open the schematic of the implemented design.
You will see that the implemented design no longer shows AND, OR, and
NOT gates. Instead, it shows that Vivado implemented your design with
several small ROMs or LUTs (Look UP Tables).

![](media/vv13.png){width="6.5in" height="4.0875in"}

18\. Select "Generate Bitstream" from the bottom of the left menu. This
is turning your design into a file that can be dumped into the FPGA. It
will take a while to generate the bitstream. You can follow the progress
by watching top right of the Vivado window.

19\. Connect the Basys3 to the computer using the USB cable and turn on
the Basys3 power switch.

20\. Select "Open Hardware Manager" from the bottom of the left menu,
and select "Open Target", then "Auto Connect". Once the computer has
connected to the Basys3, you are ready to dump the configuration data
into the FPGA. Select "Program Device".

![](media/vv14.png){width="5.0875in" height="3.4220483377077864in"}

You are now running the design on the Basys3! Use the three switches on
the bottom right as your "Left", "Stop", and "Right" signals. The car
lights are shown on the seven-segment display.

[Optional Simulation]{.underline}

Generally, a complex design will require several simulations before you
are ready to synthesize your design. To run a simulation on your
circuit, you will need to create a test bench. This is a file that
emulates the switches on the Basys3 board so that a simulation of the
outputs can be done. A testbench file has already been created, called
"Lab5\_RR\_tb.v". Download this file from the Lab5 module in Canvas and
add it to your project as follows:

![Graphical user interface, text, application, email Description
automatically generated](media/vv15.png){width="4.861488407699038in"
height="3.3230555555555554in"}

Select "Add a Source" from the side menu, then select the "Add or create
simulation sources" button.

![Graphical user interface, text, application, email Description
automatically generated](media/vv16.png){width="4.8826968503937005in"
height="3.3088615485564303in"}

Select "Add Files" or click on the "+" button".

![Graphical user interface, text, application Description automatically
generated](media/vv17.png){width="4.95599956255468in"
height="2.3562182852143483in"}

Navigate to the location you placed the "Lab5\_RR\_tb.v" file and add it
to your design.

![Graphical user interface, text, application, email Description
automatically generated](media/vv18.png){width="4.9640004374453195in"
height="3.899073709536308in"}

Run A Behavioral Simulation

After the simulation runs, select the Untitled 1 tab and expand the
window (the square on the top right).

![Graphical user interface Description automatically
generated](media/vv19.png){width="3.800695538057743in"
height="3.195670384951881in"}

To zoom out to full view, click on the button with four diverging
arrows. If the simulation looks like the above screenshot, the
simulation is not yet done.

![](media/vv21.png){width="6.5in" height="0.5840277777777778in"}

To finish the simulation, click on the "run simulation" button (shown
above).

![](media/vv20.png){width="4.578431758530184in"
height="2.668794838145232in"}

Zoom to fit (the four diverging arrows) and see if you can understand
the simulation results!
