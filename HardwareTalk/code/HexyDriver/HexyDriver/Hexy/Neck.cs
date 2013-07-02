public class Neck
{
    private ServotorController _Controller;
    private int _servoNum;

    public Neck(ServotorController controller, int servoNum)
    {
        _Controller = controller;
        _servoNum = servoNum;
    }

    public void set(int deg)
    {
        _Controller.Servos[_servoNum].setPos(deg);
    }
}