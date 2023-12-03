ECEN 160L

Lab 0 - LED Driver Circuit

Construct the circuit shown below on a protoboard following the
instructions below:

![](media/image1.tiff){width="3.1666666666666665in"
height="2.7497036307961507in"}

The components and wires needed are in the parts bin shown below. The
parts bins also have batteries and resistors that will not be used. Use
only components from your parts bin for measurements.

![](media/image2.tiff){width="4.847938538932634in"
height="3.638888888888889in"}

Step 1: Verify that you have the following components:

![](media/image3.tiff){width="6.041666666666667in"
height="4.527777777777778in"}

Step 2: Assemble the tools that will be used to construct this circuit.
You will need the Digital Multi-Meter (DMM), 2 sets of banana plugs with
alligator clips on one end, a protoboard and possibly wire strippers and
needle nose pliers, as shown below:

![](media/image4.tiff){width="5.643939195100613in"
height="2.7520034995625546in"}

Step 3: Insert the SN74LS04 and SN74LS05 along the middle of the
protoboard/breadboard. Make sure all the pins from the ICs are properly
inserted into the breadboard (make sure the ICs are aligned so that the
indents are to the left as shown in the image below). Next connect a
power wire from the top power wire to pin location 14 on each IC and a
ground wire to pin location 7 from the bottom strip as shown below:

![](media/image5.tiff){width="6.160448381452318in"
height="3.1527777777777777in"}

Review the data sheet for a 74LS04 to see a schematic of the part. The
power (Vcc) and ground (GND) as well as input and output pin assignments
are the same for the SN74LS04 and SN74LS05 as for the SN74LS04 hex
inverter IC. Relate the step-by-step instructions given here to the data
sheet and the schematic show in step 4.

Note that the +5 supply is connected to the Vcc pin (pin 14 which is the
positive voltage supply pin) of the integrated circuit (IC or \'chip\').
The ground or negative supply is connected to the \'GND\' (pin 7) of the
IC. All ICs need electrical power to work. The ICs used in this circuit
each have six inverters. Only three of the twelve inverters in the two
ICs are used to make the circuit work. When the chip has power, if the
input has a voltage on it close to 0 volts (a low) the output of the
inverter will have a \'high\' voltage on it. When the input of an
inverter has a \'high\' voltage on it, the output of the inverter will
have a \'low\' voltage on it.

Step 4: Insert the switch into the protoboard. Run a power wire to one
of the outside pins and a ground wire to the other. The middle pin is
OUT and will be run to the first inverter in location 1 on the SN74LS04
chip. At this point, the circuit should look like the following:

![](media/image6.tiff){width="5.886363735783027in"
height="2.1678674540682414in"}

Step 5: Connect the output of the first inverter with the input of the
second (this is done by the purple jumper from pin location 2 to pin
location 3 on the SN74LS04). At this point, the circuit should look like
the following:

![](media/image7.tiff){width="5.868547681539807in"
height="2.1287871828521436in"}

Step 6: Insert a jumper wire from the 2nd inverter output (pin location
4) to the input location 9 on the SN74LS05. Next, we can add the
resistor and the LED. Remember that the resistor and LED are in series
and the flat edge of the LED should be pointing towards the IC, while
the resistor is connected to power on the top

![](media/image8.tiff){width="5.303030402449694in"
height="1.886654636920385in"}

![](media/image9.tiff){width="5.263076334208224in"
height="1.8560608048993876in"}

Step 7: Once the circuit is complete, we can take the banana
plug/alligator clips and hook them up to the fixed 5V on the power
supply.

![](media/image10.tiff){width="4.325757874015748in"
height="3.2416076115485564in"}

Step 8: Turn on the power supply and toggle the switch on the
proto-board. It should turn the LED on and off.

Demonstrate the correct circuit operation to an instructor or lab
assistant and have him/her sign it off using the I-Learn \"Lab \#0 -
Correct Circuit Operation\" item.

![](media/image11.tiff){width="5.7037040682414695in"
height="2.4785728346456692in"}

Record in your conclusions for this lab, any issues, insights, and/or
problems that occurred while doing this step of the lab. If you had
equipment issues you should provide the \"bench number\" of the bench
you are using (the bench number should be found on the front edge of the
bench shelf) and the bin number of the parts you are using for this lab.
