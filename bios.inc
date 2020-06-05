;---------------------------------------------------------------
;                         MSX 1 BIOS Entries
;---------------------------------------------------------------

CHKRAM equ #0000
/*
    Hardware : MSX1
    Function : Tests RAM and sets RAM slot for the system
    Registers: All
    Remark   : After this, a jump must be made to INIT, for further initialisation.
*/

SYNCHR equ #0008
/*
    Hardware : MSX1
    Function : Tests whether the character of (HL) is the specified character
               if not, it generates SYNTAX ERROR, otherwise it goes to CHRGTR (#0010)
    Input    : Set the character to be tested in (HL) and the character to be
               compared next to RST instruction which calls this routine (inline parameter)
    Output   : HL is increased by one and A receives (HL), When the tested character is
               numerical, the carry flag is set the end of the statement (00h or 3Ah) causes
               the zero flag to be set
    Registers: AF, HL
*/

RDSLT equ #000C
/*
    Hardware : MSX1
    Function : Reads the value of an address in another slot
    Input    : A  - ExxxSSPP  Slot-ID
               │        ││└┴─ Primary slot number (00-11)
               │        └┴─── Secondary slot number (00-11)
               └───────────── Expanded slot (0 = no, 1 = yes)
               HL - Address to read
    Output   : A  - Contains the value of the read address
    Registers: AF, C, DE
    Remark   : This routine turns off the interupt, but won't turn it on again
*/

CHRGTR equ #0010
/*
    Hardware : MSX1
    Function : Gets the next character (or token) of the Basic text
    Input    : HL - Address last character
    Output   : HL - Points to the next character
               A  - Contains the character
               Carry flag set if it's a number
               Zero flag set if it's the end of the statement
    Registers: AF, HL
*/

WRSLT equ #0014
/*
    Hardware : MSX1
    Function : Writes a value to an address in another slot.
    Input    : A  - Slot ID, see RDSLT
               HL - Address
               E  - Value
    Registers: AF, BC, D
    Remark   : See RDSLT
*/

OUTDO equ #0018
/*
    Hardware : MSX1
    Function : Output to current output channel (printer, file, etc.)
    Input    : A  - PRTFIL, PRTFLG
    Remark   : Used in basic, in ML it's pretty difficult
*/

CALSLT equ #001C
/*
    Hardware : MSX1
    Function : Executes inter-slot call.
    Input    : IY - High byte with slot ID, see RDSLT
               IX - The address that will be called
    Remark   : Variables can never be given in alternative registers or IX and IY
*/

DCOMPR equ #0020
/*
    Hardware : MSX1
    Function : Compares HL with DE
    Input    : HL, DE
    Output   : Zero flag set if HL and DE are equal. Carry flag set if HL is less than DE.
    Registers: AF
*/

ENASLT equ #0024
/*
    Hardware : MSX1
    Function : Switches indicated slot at indicated page on perpetually
    Input    : A - Slot ID, see RDSLT
               H - Bit 6 and 7 must contain the page number (00-11)
*/

GETYPR equ #0028
/*
    Hardware : MSX1
    Function : Returns Type of DAC
    Input    : DAC
    Output   : S,Z,P/V, CY
    Registers: AF
    Remark   : Not a very clear routine to me, please mail us if you know more about it.
*/
CALLF equ #0030
/*
  Hardware : MSX1
  Function : Executes an interslot call
  Output   : Depends on the calling routine
  Registers: AF, and the other registers depending on the calling routine
  Remark   : The following is the calling sequence:
             RST #30
             DB destination slot ID, see RDSLT
             DW destination address
*/

KEYINT equ #0038
/*
  Hardware : MSX1
  Function : Executes the timer interrupt process routine
*/

; Initialization-routines

INITIO equ #003B
/*
  Hardware : MSX1
  Function : Initialises the device
  Registers: All
*/

INIFNK equ #003E
/*
  Hardware : MSX1
  Function : Initialises the contents of the function keys
  Registers: All
*/

; VDP routines

DISSCR equ #0041
/*
  Hardware : MSX1
  Function : Inhibits the screen display
  Registers: AF, BC
*/

ENASCR equ #0044
/*
  Hardware : MSX1
  Function : Displays the screen
  Registers: AF, BC
*/

WRTVDP equ #0047
/*
  Hardware : MSX1
  Function : Write data in the VDP-register
  Input    : B  - Data to write
             C  - Number of the register
  Registers: AF, BC
*/

RDVRM equ #004A
/*
  Hardware : MSX1
  Function : Reads the content of VRAM
  Input    : HL - Address read
  Output   : A  - Value which was read
  Registers: AF
*/

WRTVRM equ #004D
/*
  Hardware : MSX1
  Function : Writes data in VRAM
  Input    : HL - Address write
             A  - Value write
  Registers: AF
*/

SETRD equ #0050
/*
  Hardware : MSX1
  Function : Enable VDP to read
  Input    : HL - For VRAM-address
  Registers: AF
*/

SETWRT equ #0053
/*
  Hardware : MSX1
  Function : Enable VDP to write
  Input    : HL - Address
  Registers: AF
*/

FILVRM equ #0056
/*
  Hardware : MSX1
  Function : Fill VRAM with value
  Input    : A  - Data byte
             BC - Length of the area to be written
             HL - Start address
  Registers: AF, BC
*/

LDIRMV equ #0059
/*
  Hardware : MSX1
  Function : Block transfer to memory from VRAM
  Input    : BC - Block length
             DE - Start address of memory
             HL - Start address of VRAM
  Registers: All
*/

LDIRVM equ #005C
/*
  Hardware : MSX1
  Function : Block transfer to VRAM from memory
  Input    : BC - Block length
             DE - Start address of VRAM
             HL - Start address of memory
  Registers: All
*/

CHGMOD equ #005F
/*
  Hardware : MSX1
  Function : Switches to given screen mode
  Input    : A  - Screen mode
  Registers: All
*/

CHGCLR equ #0062
/*
  Hardware : MSX1
  Function : Changes the screen colors
  Input    : Foreground color in FORCLR
             Background color in BAKCLR
             Border color in BDRCLR
  Registers: All
*/

NMI equ #0066
/*
  Hardware : MSX1
  Function : Executes non-maskable interupt handling routine
*/

CLRSPR equ #0069
/*
  Hardware : MSX1
  Function : Initialises all sprites
  Input    : SCRMOD
  Registers: All
*/

INITXT equ #006C
/*
  Hardware : MSX1
  Function : Switches to SCREEN 0 (text screen with 40×24 characters)
  Input    : TXTNAM, TXTCGP
  Registers: All
*/

INIT32 equ #006F
/*
  Hardware : MSX1
  Function : Switches to SCREEN 1 (text screen with 32×24 characters)
  Input    : T32NAM, T32CGP, T32COL, T32ATR, T32PAT
  Registers: All
*/

INIGRP equ #0072
/*
  Hardware : MSX1
  Function : Switches to SCREEN 2 (high resolution screen with 256×192 pixels)
  Input    : GRPNAM, GRPCGP, GRPCOL, GRPATR, GRPPAT
  Registers: All
*/

INIMLT equ #0075
/*
  Hardware : MSX1
  Function : Switches to SCREEN 3 (multi-color screen with 64×48 pixels)
  Input    : MLTNAM, MLTCGP, MLTCOL, MLTATR, MLTPAT
  Registers: All
*/

SETTXT equ #0078
/*
  Hardware : MSX1
  Function : Switches VDP to SCREEN 0 mode
  Input    : See INITXT
  Registers: All
*/

SETT32 equ #007B
/*
  Hardware : MSX1
  Function : Switches VDP to SCREEN 1 mode
  Input    : See INIT32
  Registers: All
*/

SETGRP equ #007E
/*
  Hardware : MSX1
  Function : Switches VDP to SCREEN 2 mode
  Input    : See INIGRP
  Registers: All
*/

SETMLT equ #0081
/*
  Hardware : MSX1
  Function : Switches VDP to SCREEN 3 mode
  Input    : See INIMLT
  Registers: All
*/

CALPAT equ #0084
/*
  Hardware : MSX1
  Function : Returns the address of the sprite pattern table
  Input    : A  - Sprite ID
  Output   : HL - For the address
  Registers: AF, DE, HL
*/

CALATR equ #0087
/*
  Hardware : MSX1
  Function : Returns the address of the sprite attribute table
  Input    : A  - Sprite number
  Output   : HL - For the address
  Registers: AF, DE, HL
*/

GSPSIZ equ #008A
/*
  Hardware : MSX1
  Function : Returns current sprite size
  Output   : A  - Sprite size in bytes
             Carry flag set when size is 16×16 sprites otherwise Carry flag is reset
  Registers: AF
*/

GRPPRT equ #008D
/*
  Hardware : MSX1
  Function : Displays a character on the graphic screen
  Input    : A  - ASCII value of the character to print
*/

; PSG routines

GICINI equ #0090
/*
  Hardware : MSX1
  Function : Initialises PSG and sets initial value for the PLAY statement
  Registers: All
*/

WRTPSG equ #0093
/*
  Hardware : MSX1
  Function : Writes data to PSG register
  Input    : A  - PSG register number
             E  - Data write
*/

RDPSG equ #0096
/*
  Hardware : MSX1
  Function : Reads value from PSG register
  Input    : A  - PSG register read
  Output   : A  - Value read
*/

STRTMS equ #0099
/*
  Hardware : MSX1
  Function : Tests whether the PLAY statement is being executed as a background
             task. If not, begins to execute the PLAY statement
  Registers: All
*/

;Console routines

CHSNS equ #009C
/*
  Hardware : MSX1
  Function : Tests the status of the keyboard buffer
  Output   : Zero flag set if buffer is empty, otherwise not set
  Registers: AF
*/

CHGET equ #009F
/*
  Hardware : MSX1
  Function : One character input (waiting)
  Output   : A  - ASCII code of the input character
  Registers: AF
*/

CHPUT equ #00A2
/*
  Hardware : MSX1
  Function : Displays one character
  Input    : A  - ASCII code of character to display
*/

LPTOUT equ #00A5
/*
  Hardware : MSX1
  Function : Sends one character to printer
  Input    : A  - ASCII code of character to send
  Output   : Carry flag set if failed
  Registers: F
*/

LPTSTT equ #00A8
/*
  Hardware : MSX1
  Function : Tests printer status
  Output   : A  - #FF and zero flag reset if printer is ready
                  #00 and zero flag set if not ready
  Registers: AF
*/

CNVCHR equ #00AB
/*
  Hardware : MSX1
  Function : Tests for the graphic header and transforms the code
  Input    : A  - Character code
  Output   : The carry flag is reset to not the graphic reader
             The carry flag and zero flag are set to the transformed code is set in A
             The carry flag is set and zero flag is reset to the untransformed code is set in A
  Registers: AF
*/

PINLIN equ #00AE
/*
  Hardware : MSX1
  Function : Stores in the specified buffer the character codes input until the return
             key or STOP key is pressed
  Output   : HL - For the starting address of the buffer -1
             Carry flag set when it ends with the STOP key
  Registers: All
*/

INLIN equ #00B1
/*
  Hardware : MSX1
  Function : Same as PINLIN except that AUGFLG (#F6AA) is set
  Output   : HL - For the starting address of the buffer -1
             Carry flag set when it ends with the STOP key
  Registers: All
*/

QINLIN equ #00B4
/*
  Hardware : MSX1
  Function : Prints a question mark and one space
  Output   : HL - For the starting address of the buffer -1
             Carry flag set when it ends with the STOP key
  Registers: All
*/

BREAKX equ #00B7
/*
  Hardware : MSX1
  Function : Tests status of CTRL-STOP
  Output   : Carry flag set when pressed
  Registers: AF
  Remark   : In this routine, interrupts are inhibited
*/

ISCNTC equ #00BA
/*
  Hardware : MSX1
  Function : Tests status of SHIFT-STOP
*/

CKCNTC equ #00BD
/*
  Hardware : MSX1
  Function : Same as ISCNTC. used in Basic
*/

BEEP equ #00C0
/*
  Hardware : MSX1
  Function : Generates beep
  Registers: All
*/

CLS equ #00C3
/*
  Hardware : MSX1
  Function : Clears the screen
  Registers: AF, BC, DE
  Remark   : Zero flag must be set to be able to run this routine
             XOR A will do fine most of the time
*/

POSIT equ #00C6
/*
  Hardware : MSX1
  Function : Moves cursor to the specified position
  Input    : H  - Y coordinate of cursor
             L  - X coordinate of cursor
  Registers: AF
*/

FNKSB equ #00C9
/*
  Hardware : MSX1
  Function : Tests whether the function key display is active (FNKFLG)
             If so, displays them, otherwise erase them
  Input    : FNKFLG (#FBCE)
  Registers: All
*/

ERAFNK equ #00CC
/*
  Hardware : MSX1
  Function : Erase functionkey display
  Registers: All
*/

DSPFNK equ #00CF
/*
  Hardware : MSX1
  Function : Displays the function keys
  Registers: All
*/

TOTEXT equ #00D2
/*
  Hardware : MSX1
  Function : Forces the screen to be in the text mode
  Registers: All
*/

; Controller routines


GTSTCK equ #00D5
/*
  Hardware : MSX1
  Function : Returns the joystick status
  Input    : A  - Joystick number to test (0 = cursors, 1 = port 1, 2 = port 2)
  Output   : A  - Direction
  Registers: All
*/

GTTRIG equ #00D8
/*
  Hardware : MSX1
  Function : Returns current trigger status
  Input    : A  - Trigger button to test
             0 = space bar
             1 = port 1, button A
             2 = port 2, button A
             3 = port 1, button B
             4 = port 2, button B
  Output   : A  - #00 trigger button not pressed
                  #FF trigger button pressed
  Registers: AF
*/

GTPAD equ #00DB
/*
  Hardware : MSX1
  Function : Returns current touch pad status
  Input    : A  - Function call number. Fetch device data first, then read.

             [ 0]   Fetch touch pad data from port 1 (#FF if available)
             [ 1]   Read X-position
             [ 2]   Read Y-position
             [ 3]   Read touchpad status from port 1 (#FF if pressed)

             [ 4]   Fetch touch pad data from port 2 (#FF if available)
             [ 5]   Read X-position
             [ 6]   Read Y-position
             [ 7]   Read touchpad status from port 2 (#FF if pressed)

  Output   : A  - Value
  Registers: All
  Remark   : On MSX2, function call numbers 8-23 are forwarded to
             NEWPAD in the SubROM.
*/

GTPDL equ #00DE
/*
  Hardware : MSX1
  Function : Returns current value of paddle
  Input    : A  - Paddle number
  Output   : A  - Value
  Registers: All
*/

;Tape device routines

TAPION equ #00E1
/*
  Hardware : MSX1
  Function : Reads the header block after turning the cassette motor on
  Output   : Carry flag set if failed
  Registers: All
*/

TAPIN equ #00E4
/*
  Hardware : MSX1
  Function : Read data from the tape
  Output   : A  - Read value
             Carry flag set if failed
  Registers: All
*/

TAPIOF equ #00E7
/*
  Hardware : MSX1
  Function : Stops reading from the tape
*/

TAPOON equ #00EA
/*
  Hardware : MSX1
  Function : Turns on the cassette motor and writes the header
  Input    : A  - #00 short header
              not #00 long header
  Output   : Carry flag set if failed
  Registers: All
*/

TAPOUT equ #00ED
/*
  Hardware : MSX1
  Function : Writes data on the tape
  Input    : A  - Data to write
  Output   : Carry flag set if failed
  Registers: All
*/

TAPOOF equ #00F0
/*
  Hardware : MSX1
  Function : Stops writing on the tape
*/

STMOTR equ #00F3
/*
  Hardware : MSX1
  Function : Sets the cassette motor action
  Input    : A  - #00 stop motor
                  #01 start motor
                  #FF reverse the current action
  Registers: AF
*/

;Queue routines

LFTQ equ #00F6
/*
  Hardware : MSX1
  Function : Gives number of bytes in queue
  Output   : A  - Length of queue in bytes
  Remark   : Internal use
*/

PUTQ equ #00F9
/*
  Hardware : MSX1
  Function : Put byte in queue
  Remark   : Internal use
*/

;Graphic routines

RIGHTC equ #00FC
/*
  Hardware : MSX1
  Function : Shifts screen pixel to the right
  Registers: AF
*/

LEFTC equ #00FF
/*
  Hardware : MSX1
  Function : Shifts screen pixel to the left
  Registers: AF
*/

UPC equ #0102
/*
  Hardware : MSX1
  Function : Shifts screen pixel up
  Registers: AF
*/

TUPC equ #0105
/*
  Hardware : MSX1
  Function : Tests whether UPC is possible, if possible, execute UPC
  Output   : Carry flag set if operation would end outside the screen
  Registers: AF
*/

DOWNC equ #0108
/*
  Hardware : MSX1
  Function : Shifts screen pixel down
  Registers: AF
*/

TDOWNC equ #010B
/*
  Hardware : MSX1
  Function : Tests whether DOWNC is possible, if possible, execute DOWNC
  Output   : Carry flag set if operation would end outside the screen
  Registers: AF
*/

SCALXY equ #010E
/*
  Hardware : MSX1
  Function : Scales X and Y coordinates
*/

MAPXY equ #0111
/*
  Hardware : MSX1
  Function : Places cursor at current cursor address
*/

FETCHC equ #0114
/*
  Hardware : MSX1
  Function : Gets current cursor addresses mask pattern
  Output   : HL - Cursor address
             A  - Mask pattern
*/

STOREC equ #0117
/*
  Hardware : MSX1
  Function : Record current cursor addresses mask pattern
  Input    : HL - Cursor address
             A  - Mask pattern
*/

SETATR equ #011A
/*
  Hardware : MSX1
  Function : Set attribute byte
*/

READC equ #011D
/*
  Hardware : MSX1
  Function : Reads attribute byte of current screen pixel
*/

SETC equ #0120
/*
  Hardware : MSX1
  Function : Returns current screen pixel of specified attribute byte
*/

NSETCX equ #0123
/*
  Hardware : MSX1
  Function : Set horizontal screen pixels
*/

GTASPC equ #0126
/*
  Hardware : MSX1
  Function : Gets screen relations
  Output   : DE, HL
  Registers: DE, HL
*/

PNTINI equ #0129
/*
  Hardware : MSX1
  Function : Initalises the PAINT instruction
*/

SCANR equ #012C
/*
  Hardware : MSX1
  Function : Scans screen pixels to the right
*/

SCANL equ #012F
/*
  Hardware : MSX1
  Function : Scans screen pixels to the left
*/

; Misc routines

CHGCAP equ #0132
/*
  Hardware : MSX1
  Function : Alternates the CAPS lamp status
  Input    : A  - #00 is lamp on
              not #00 is lamp off
  Registers: AF
*/

CHGSND equ #0135
/*
  Hardware : MSX1
  Function : Alternates the 1-bit sound port status
  Input    : A  - #00 to turn off
              not #00 to turn on
  Registers: AF
*/

RSLREG equ #0138
/*
  Hardware : MSX1
  Function : Reads the primary slot register
  Output   : A  - For the value which was read
             33221100
             ││││││└┴─ Page 0 (#0000-#3FFF)
             ││││└┴─── Page 1 (#4000-#7FFF)
             ││└┴───── Page 2 (#8000-#BFFF)
             └┴─────── Page 3 (#C000-#FFFF)
  Registers: A
*/

WSLREG equ #013B
/*
  Hardware : MSX1
  Function : Writes value to the primary slot register
  Input    : A  - Value to write, see RSLREG
*/

RDVDP equ #013E
/*
  Hardware : MSX1
  Function : Reads VDP status register
  Output   : A  - Value which was read
  Registers: A
*/

SNSMAT equ #0141
/*
  Hardware : MSX1
  Function : Returns the value of the specified line from the keyboard matrix
  Input    : A  - For the specified line
  Output   : A  - For data (the bit corresponding to the pressed key will be 0)
  Registers: AF
*/

PHYDIO equ #0144
/*
  Hardware : MSX1
  Function : Executes I/O for mass-storage media like disks
  Input    : F  - Set carry to write, reset carry to read
             A  - Drive number (0 = A:, 1 = B:, etc.)
             B  - Number of sectors
             C  - Media ID of the disk
             DE - Begin sector
             HL - Begin address in memory
  Output   : F  - Carry set on error
             A  - Error code (only if carry set)
                  0 = Write protected
                  2 = Not ready
                  4 = Data error
                  6 = Seek error
                  8 = Record not found
                  10 = Write error
                  12 = Bad parameter
                  14 = Out of memory
                  16 = Other error
             B  - Number of sectors actually written or read
  Registers: All
  Remark   : Interrupts may be disabled afterwards. On some hard disk interfaces,
             when bit 7 of register C is set, a 23-bit addressing scheme is used
             and bits 0-6 of register C contain bits 23-16 of the sector number.
*/

FORMAT equ #0147
/*
  Hardware : MSX1
  Function : Initialises mass-storage media like formatting of disks
  Registers: All
  Remark   : In minimum configuration only a HOOK is available
*/

ISFLIO equ #014A
/*
  Hardware : MSX1
  Function : Tests if I/O to device is taking place
  Output   : A  - #00 if not taking place
              not #00 if taking place
  Registers: AF
*/

OUTDLP equ #014D
/*
  Hardware : MSX1
  Function : Printer output
  Input    : A  - Code to print
  Registers: F
  Remark   : Differences with LPTOUT:
             1. TAB is expanded to spaces
             2. For non-MSX printers, Hiragana is transformed to katakana
                and graphic characters are transformed to 1-byte characters
             3. If failed, device I/O error occurs
*/

GETVCP equ #0150
/*
  Hardware : MSX1
  Function : Returns pointer to play queue
  Input    : A  - Channel number
  Output   : HL - Pointer
  Registers: AF
  Remark   : Only used to play music in background
*/

GETVC2 equ #0153
/*
  Hardware : MSX1
  Function : Returns pointer to variable in queue number VOICEN (byte at #FB38)
  Input    : L  - Pointer in play buffer
  Output   : HL - Pointer
  Registers: AF
*/

KILBUF equ #0156
/*
  Hardware : MSX1
  Function : Clear keyboard buffer
  Registers: HL
*/

CALBAS equ #0159
/*
  Hardware : MSX1
  Function : Executes inter-slot call to the routine in BASIC interpreter
  Input    : IX - For the calling address
  Output   : Depends on the called routine
  Registers: Depends on the called routine
*/

;---------------------------------------------------------------
;                         MSX 2 BIOS Entries
;---------------------------------------------------------------

SUBROM equ #015C
/*
  Hardware : MSX2
  Function : Calls a routine in SUB-ROM
  Input    : IX - Address of routine in SUB-ROM
  Output   : Depends on the routine
  Registers: Alternative registers, IY
  Remark   : Use of EXTROM or CALSLT is more convenient.
             In IX an extra value to the routine can be given by first
             pushing it to the stack.
*/
EXTROM equ #015F
/*
  Hardware : MSX2
  Function : Calls a routine in SUB-ROM. Most common way
  Input    : IX - Address of routine in SUB-ROM
  Output   : Depends on the routine
  Registers: Alternative registers, IY
  Remark   : Use: LD IX,address
                  CALL EXTROM
*/

CHKSLZ equ #0162
/*
  Hardware : MSX2
  Function : Search slots for SUB-ROM
  Registers: All
  CHKNEW
  Address  : #0165
  Function : Tests screen mode
  Output   : Carry flag set if screenmode = 5, 6, 7 or 8
  Registers: AF
*/

EOL equ #0168
/*
  Hardware : MSX2
  Function : Deletes to the end of the line
  Input    : H  - X coordinate of cursor
             L  - Y coordinate of cursor
  Registers: All
*/

BIGFIL equ #016B
/*
  Hardware : MSX2
  Function : Same function as FILVRM (with 16-bit VRAM-address).
  Input    : HL - Address
             BC - Length
             A  - Data
  Registers: AF,BC
*/

NSETRD equ #016E
/*
  Hardware : MSX2
  Function : Same function as SETRD (with 16-bit VRAM-address).
  Input    : HL - VRAM address
  Registers: AF
*/

NSTWRT equ #0171
/*
  Hardware : MSX2
  Function : Same function as SETWRT (with 16-bit VRAM-address).
  Input    : HL - VRAM address
  Registers: AF
*/

NRDVRM equ #0174
/*
  Hardware : MSX2
  Function : Reads VRAM like in RDVRM (with 16-bit VRAM-address).
  Input    : HL - VRAM address
  Output   : A  - Read value
  Registers: F
*/

NWRVRM equ #0177
/*
  Hardware : MSX2
  Function : Writes to VRAM like in WRTVRM (with 16-bit VRAM-address).
  Input    : HL - VRAM address
             A  - Value to write
  Registers: AF
*/

;---------------------------------------------------------------
;                         MSX 2+ BIOS Entries
;---------------------------------------------------------------

RDRES equ #017A
/*
  Hardware : MSX2+
  Function : Read value of I/O port #F4
  Input    : None
  Output   : A = value read
  Registers: AF
*/

WRRES equ #017D
/*
  Hardware : MSX2+
  Function : Write value to I/O port #F4
  Input    : A = value to write
             When bit 7 is reset it shows the MSX 2+ startup screen on boot,
             and counts and initialises the RAM.
  Output   : None
  Registers: None
*/

;---------------------------------------------------------------
;                         MSX turbo R BIOS Entries
;---------------------------------------------------------------

CHGCPU equ #0180
/*
  Hardware : MSXTR
  Function : Changes CPU mode
  Input    : A = LED 0 0 0 0 0 x x
                  │            0 0 = Z80 (ROM) mode
                  │            0 1 = R800 ROM  mode
                  │            1 0 = R800 DRAM mode
                 LED indicates whether the Turbo LED is switched with the CPU
  Output   : None
  Registers: None
*/

GETCPU equ #0183
/*
  Hardware : MSXTR
  Function : Returns current CPU mode
  Input    : None
  Output   : A = 0 0 0 0 0 0 x x
                             0 0 = Z80 (ROM) mode
                             0 1 = R800 ROM  mode
                             1 0 = R800 DRAM mode
  Registers: AF
*/

PCMPLY equ #0186
/*
  Hardware : MSXTR
  Function : Plays specified memory area through the PCM chip
  Input    : A = v 0 0 0 0 0 x x
                 │           │ │
                 │           └─┴── Quality parameter (Speed: 0 = Fast)
                 └──────────────── VRAM usage flag
             HL= Start address in RAM or VRAM
             BC= Length of area to play
             D = Bit 0 = Bit 17 of area length when using VRAM
             E = Bit 0 = Bit 17 os start address when using VRAM
  Output   : Carry flag set when aborted with CTRL-STOP
  Registers: All
*/

PCMREC equ #0189
/*
  Hardware : MSXTR
  Function : Records audio using the PCM chip into the specified memory area
  Input    : A = v t t t t c x x
                 │ │ │ │ │ │ │ │
                 │ │ │ │ │ │ └─┴── Quality parameter (Speed: 0 = Fast)
                 │ │ │ │ │ └────── Zero-data compression
                 │ └─┴─┴─┴──────── Treshold
                 └──────────────── VRAM usage flag
             HL= Start address in RAM or VRAM
             BC= Length of area to play
             D = Bit 0 = Bit 17 of area length when using VRAM
             E = Bit 0 = Bit 17 os start address when using VRAM
  Output   : Carry flag set when aborted with CTRL-STOP
  Registers: All
*/

; © 2020 MSX Assembly Page. MSX is a trademark of MSX Licensing Corporation.
