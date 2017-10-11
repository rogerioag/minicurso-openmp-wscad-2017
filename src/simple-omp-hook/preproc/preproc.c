#define SIGNAL1 SignalName1
#define SIGNAL2 SignalName2

#define MAKE_FN_NAME(x) void  Callback_ ## x (void)
#define FUNCTION_NAME(signal) MAKE_FN_NAME(signal)

FUNCTION_NAME(SIGNAL1)
{
    return;
}
