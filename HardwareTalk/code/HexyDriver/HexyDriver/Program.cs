using System.Threading;
using SharpDX.XInput;

public static class Program
{
    public static void Main()
    {
        var gamepad = new GamepadState(UserIndex.Any);

        bool exit = false;
        while (!exit)
        {
            if (!gamepad.Connected)
            {
                Thread.Sleep(500);

                continue;
            }

            gamepad.Update();

            // TODO Drive hexy
        }
    }
}