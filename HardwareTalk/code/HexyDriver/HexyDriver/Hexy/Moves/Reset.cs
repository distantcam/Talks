﻿using System;
using System.Threading;

public class Reset : BaseMove
{
    public override string MovementName
    {
        get { return "Reset"; }
    }

    public override void ExecuteAction(Hexapod hexy)
    {
        var deg = -30;
        // pickup and put all the feet centered on the floor
        hexy.LeftFront.replantFoot(-deg, 0.3f);
        hexy.RightMiddle.replantFoot(1, 0.3f);
        hexy.LeftBack.replantFoot(deg, 0.3f);

        Thread.Sleep(1000);

        Console.WriteLine(hexy.LeftFront.GetStatus());
        Console.WriteLine(hexy.RightMiddle.GetStatus());
        Console.WriteLine(hexy.LeftBack.GetStatus());

        hexy.RightFront.replantFoot(deg, 0.3f);
        hexy.LeftMiddle.replantFoot(1, 0.3f);
        hexy.RightBack.replantFoot(-deg, 0.3f);

        Thread.Sleep(1000);

        // set all the hip angle to what they should be while standing
        hexy.LeftFront.hip(-deg);
        hexy.RightMiddle.hip(1);
        hexy.LeftBack.hip(deg);
        hexy.RightFront.hip(deg);
        hexy.LeftMiddle.hip(1);
        hexy.RightBack.hip(-deg);
    }
}