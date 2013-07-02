public abstract class BaseMove
{
    public abstract string MovementName { get; }

    public abstract void ExecuteAction(Hexapod hexy);
}