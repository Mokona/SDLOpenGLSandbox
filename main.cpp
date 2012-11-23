#include "SDLSandbox.h"

int main(int argc, char **argv)
{
    SDLSandbox sandbox;

    sandbox.Init(&argc, argv);
    sandbox.Run();
}

