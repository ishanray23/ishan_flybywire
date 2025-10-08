Sub Process_Globals
    'These global variables will be declared once when the application starts.'
    'Public variables can be accessed from all modules.'
    Public Serial1 As Serial

    Private Servo As Servo
    Private Potentiometer As Pin
    Private SSD As AdafruitSSD1306
    Private BC As ByteConverter
End Sub

Private Sub AppStart
    Serial1.Initialize(115200)
    Log("AppStart")

    Potentiometer.Initialize(0, Potentiometer.AnalogRead)
    Servo.Attach(2)

    SSD.InitializeI2C(4, 0x3c) 'Initialise the display on address 0x3c'
    SSD.GFX.ConfigureText(4, SSD.WHITE, False) 'Set display font size and colour'

    AddLooper("Loopey")
End Sub

Sub Loopey
    Servo.write(MapRange(Potentiometer.AnalogRead, 0, 1023, 0, 179)) 'Read potentiometer value (0 to 1023) and set servo position to the mapped value'

    SSD.ClearDisplay
    SSD.GFX.SetCursor(20, 3)
    SSD.GFX.DrawText(JoinStrings(Array As String(Servo.Read, BC.StringFromBytes(Array As Byte(247))))) 'Read the servo and display the angle'
    SSD.Display
End Sub
