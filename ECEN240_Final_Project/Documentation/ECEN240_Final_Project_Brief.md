![](media/image1.tiff){width="5.016806649168854in"
height="2.9598162729658792in"}

**Figure 1 -- A 4-bit CPU Block Diagram**

> **Microprocessor Instruction Set**
>
> Large microprocessors have dozens (or even hundreds) of instructions
> (operations) in their instruction set. The number of bits required for
> each instruction will vary from processor to processor. This
> microprocessor architecture has nine instructions which may be
> represented in assembly code format or in 16-bit machine code format
> (see Table 1).

+-------------+-------------+-------------+-------------+-------------+
| **Opcode**  | *           | **          | **Assembly  | **Machine   |
|             | *Mnemonic** | Instruction | Code        | Code        |
|             |             | Operation** | Format**    | Format\     |
|             |             |             |             | (16-bits)** |
+=============+=============+=============+=============+=============+
| **0000**    | **NOP**     | **No        | **NOP**     | **0000 0000 |
|             |             | Operation** |             | 0000 0000** |
+-------------+-------------+-------------+-------------+-------------+
| **0001**    | **LD**      | **Rd \<=    | **LD Rd,    | **0001 0ddd |
|             |             | Data**      | Data**      | 0000 DDDD** |
+-------------+-------------+-------------+-------------+-------------+
| **0010**    | **MOV**     | **Rd \<=    | **MOV Rd,   | **0010 0ddd |
|             |             | Ra**        | Ra**        | 0aaa 0000** |
+-------------+-------------+-------------+-------------+-------------+
| **0011**    | **DISP**    | **Display   | **DISP Ra,  | **0011 0000 |
|             |             | {Ra, Rb} on | Rb**        | 0aaa 0bbb** |
|             |             | ASCII       |             |             |
|             |             | display**   |             |             |
+-------------+-------------+-------------+-------------+-------------+
| **0100**    | **XOR**     | **Rd \<= Ra | **XOR Rd,   | **0100 0ddd |
|             |             | XOR Rb**    | Ra, Rb**    | 0aaa 0bbb** |
+-------------+-------------+-------------+-------------+-------------+
| **0101**    | **AND**     | **Rd \<= Ra | **AND Rd,   | **0101 0ddd |
|             |             | AND Rb**    | Ra, Rb**    | 0aaa 0bbb** |
+-------------+-------------+-------------+-------------+-------------+
| **0110**    | **OR**      | **Rd \<= Ra | **OR Rd,    | **0110 0ddd |
|             |             | OR Rb**     | Ra, Rb**    | 0aaa 0bbb** |
+-------------+-------------+-------------+-------------+-------------+
| **0111**    | **ADD**     | **Rd \<= Ra | **ADD Rd,   | **0111 0ddd |
|             |             | + Rb**      | Ra, Rb**    | 0aaa 0bbb** |
+-------------+-------------+-------------+-------------+-------------+
| **1111**    | **SUB**     | **Rd \<= Ra | **SUB Rd,   | **1111 0ddd |
|             |             | - Rb**      | Ra, Rb**    | 0aaa 0bbb** |
+-------------+-------------+-------------+-------------+-------------+
|             |             | > **Ra =    | > **a =     |             |
|             |             | > Contents  | > Port A    |             |
|             |             | > of        | > Address   |             |
|             |             | > register  | > bit\      |             |
|             |             | > specified | > b = Port  |             |
|             |             | > by Addr   | > B Address |             |
|             |             | > A\        | > bit\      |             |
|             |             | > Rb =      | > d = Port  |             |
|             |             | > Contents  | > D Address |             |
|             |             | > of        | > bit\      |             |
|             |             | > register  | > D = data  |             |
|             |             | > specified | > bit**     |             |
|             |             | > by Addr   |             |             |
|             |             | > B\        |             |             |
|             |             | > Rd =      |             |             |
|             |             | > Register  |             |             |
|             |             | > specified |             |             |
|             |             | > by Addr   |             |             |
|             |             | > D\        |             |             |
|             |             | > Data =    |             |             |
|             |             | > Direct    |             |             |
|             |             | > data from |             |             |
|             |             | > the       |             |             |
|             |             | > program   |             |             |
|             |             | > PROM**    |             |             |
+-------------+-------------+-------------+-------------+-------------+
| > **When    |             |             |             |             |
| > writing   |             |             |             |             |
| > assembly  |             |             |             |             |
| > code, Ra, |             |             |             |             |
| > Rb, and   |             |             |             |             |
| > Rd are    |             |             |             |             |
| > replaced  |             |             |             |             |
| > by one of |             |             |             |             |
| > the       |             |             |             |             |
| > actual    |             |             |             |             |
| > register  |             |             |             |             |
| > names,    |             |             |             |             |
| > r0, r1,   |             |             |             |             |
| > r2, ...   |             |             |             |             |
| > r7**      |             |             |             |             |
+-------------+-------------+-------------+-------------+-------------+

**Table 1 -- CPU Instruction Set Description\
**

**Instruction Decoder PROM**

The instruction decoder will receive a 4-bit instruction (opcode) from
the program PROM (the 4 most significant bits), and configure the
control signals of the functional blocks so that the instruction may be
executed. The control signals consist of the enable signals and select
lines listed in Table 3. To design the Instruction decoder, use Figure 1
to help you identify how each of the 7 functional blocks will be
configured in order to execute each instruction. Enter these required
signal states into the truth table.

This decoder could potentially be implemented by solving K-maps of the
outputs of Table 3. Instead, you are asked to implement this logic with
a Logisim ROM from the "Memory" menu. The ROM will have 4 address bits,
and 7 data bits.

The required control bits are shown as outputs from the Instruction
Decoder Prom in Figure 1. They are:

-   Bit 0 = Register file write enable (WE).

-   Bit 1 = The ASCII display write enable (DWE).

-   Bits 3, 2 = The Register file Source Selector bits (RSS).

-   Bits 4, 5 = ALU Function Selector bits (AFS).

-   Bit 6 = Alters the addition function to subtraction (SUB).

+-------+---+-------+-------+-------+-------+-------+-------+
| **I   |   | **Bit | *     | *     | **Bit | **Bit | **Com |
| nstru |   | 6**   | *Bits | *Bits | 1\    | 0     | bined |
| ction |   |       | 5, 4\ | 3, 2\ | Di    | Reg   | Hex   |
| Oper  |   | *     | ALU   | Reg   | splay | ister | Eq    |
| ation |   | *ALU\ | Funct | ister | WE**  | WE**  | uival |
| Code  |   | SUB** | ion** | S     |       |       | ent** |
| (opco |   |       |       | ource |       |       |       |
| de)** |   |       |       | MUX** |       |       |       |
+=======+===+=======+=======+=======+=======+=======+=======+
| *     |   | 0     | 00    | 00    | 0     | 0     |       |
| *0000 |   |       |       |       |       |       |       |
| \[NO  |   |       |       |       |       |       |       |
| P\]** |   |       |       |       |       |       |       |
+-------+---+-------+-------+-------+-------+-------+-------+
| *     |   |       |       |       |       |       |       |
| *0001 |   |       |       |       |       |       |       |
| \[L   |   |       |       |       |       |       |       |
| D\]** |   |       |       |       |       |       |       |
+-------+---+-------+-------+-------+-------+-------+-------+
| *     |   |       |       |       |       |       |       |
| *0010 |   |       |       |       |       |       |       |
| \[MO  |   |       |       |       |       |       |       |
| V\]** |   |       |       |       |       |       |       |
+-------+---+-------+-------+-------+-------+-------+-------+
| *     |   |       |       |       |       |       |       |
| *0011 |   |       |       |       |       |       |       |
| \[DIS |   |       |       |       |       |       |       |
| P\]** |   |       |       |       |       |       |       |
+-------+---+-------+-------+-------+-------+-------+-------+
| *     |   |       |       |       |       |       |       |
| *0100 |   |       |       |       |       |       |       |
| \[XO  |   |       |       |       |       |       |       |
| R\]** |   |       |       |       |       |       |       |
+-------+---+-------+-------+-------+-------+-------+-------+
| *     |   |       |       |       |       |       |       |
| *0101 |   |       |       |       |       |       |       |
| \[AN  |   |       |       |       |       |       |       |
| D\]** |   |       |       |       |       |       |       |
+-------+---+-------+-------+-------+-------+-------+-------+
| *     |   |       |       |       |       |       |       |
| *0110 |   |       |       |       |       |       |       |
| \[O   |   |       |       |       |       |       |       |
| R\]** |   |       |       |       |       |       |       |
+-------+---+-------+-------+-------+-------+-------+-------+
| *     |   |       |       |       |       |       |       |
| *0111 |   |       |       |       |       |       |       |
| \[AD  |   |       |       |       |       |       |       |
| D\]** |   |       |       |       |       |       |       |
+-------+---+-------+-------+-------+-------+-------+-------+
| *     |   |       |       |       |       |       |       |
| *1111 |   |       |       |       |       |       |       |
| \[SU  |   |       |       |       |       |       |       |
| B\]** |   |       |       |       |       |       |       |
+-------+---+-------+-------+-------+-------+-------+-------+

> **Table 3 -- Instruction Decoder Truth Table**

The left hand side of the truth table (the opcode) will be the address
of each memory element of the instruction decoder PROM. The contents of
the right hand side of the truth table will be enterred as data into the
instruction decoder using hexadecimal numbers. Example: Address "0~16~"
of the PROM will contain "00~16~" corresponding to the "No Operation"
instruction.

![Table Description automatically
generated](media/image2.png){width="3.408292869641295in"
height="1.4333333333333333in"}

**Programming Template**

  -------------------------------------------------------------------------------------------------------------------------------------------
  Assembly\    Machine\     Description of Operation       Register Contents After Instruction Execution                                 
  Code         Code (Hex)                                                                                                                
  ------------ ------------ ------------------------------ ----------------------------------------------- ---- ---- ---- ---- ---- ---- ----
                                                           r7                                              r6   r5   r4   r3   r2   r1   r0

  LD r0, 0x3                Load "3" into r0                                                                                             3

  MOV r7, r0                Copy r0 contents ("3") to r7   3                                                                             3

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         

                                                                                                                                         
  -------------------------------------------------------------------------------------------------------------------------------------------
