public class SetZero : BaseMove
{
    public override string MovementName
    {
        get { return "SetZero"; }
    }

    public override void ExecuteAction(Hexapod hexy)
    {
        foreach (var servo in hexy.Controller.Servos)
        {
            servo.setPos(0);
        }
    }
}