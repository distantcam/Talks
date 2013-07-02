using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

public class Hexapod
{
    public ServotorController Controller;

    public Leg RightFront;
    public Leg RightMiddle;
    public Leg RightBack;

    public Leg LeftFront;
    public Leg LeftMiddle;
    public Leg LeftBack;

    public Leg[] Legs;
    public Leg[] Tripod1;
    public Leg[] Tripod2;

    private Neck _Neck;

    private List<BaseMove> _Movements;

    public Hexapod(ServotorController controller)
    {
        Controller = controller;

        RightFront = new Leg(Controller, "rightFront", 24, 25, 26);
        RightMiddle = new Leg(Controller, "rightMid", 20, 21, 22);
        RightBack = new Leg(Controller, "rightBack", 16, 17, 18);

        LeftFront = new Leg(Controller, "leftFront", 7, 6, 5);
        LeftMiddle = new Leg(Controller, "leftMid", 11, 10, 9);
        LeftBack = new Leg(Controller, "leftBack", 15, 14, 13);

        Legs = new Leg[]
            {
                RightFront, RightMiddle, RightBack,
                LeftFront, LeftMiddle, LeftBack
            };

        _Neck = new Neck(Controller, 31);
        Tripod1 = new Leg[] { RightFront, RightBack, LeftMiddle };
        Tripod2 = new Leg[] { LeftFront, LeftBack, RightMiddle };

        var baseType = typeof(BaseMove);
        _Movements = Assembly.GetExecutingAssembly().GetTypes()
            .Where(t => baseType.IsAssignableFrom(t)
                && t != baseType)
            .Select(t => (BaseMove)Activator.CreateInstance(t))
            .ToList();
    }

    public void Move(string moveName)
    {
        var movement = _Movements.Where(m => m.MovementName == moveName)
            .FirstOrDefault();
        if (movement != null)
        {
            movement.ExecuteAction(this);
            Console.WriteLine("Executing action {0}", movement.MovementName);
        }
    }
}