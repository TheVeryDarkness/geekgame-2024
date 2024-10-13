#include <pulse/volume.h>
#include <stdio.h>

// https://www.freedesktop.org/software/pulseaudio/doxygen/volume.html
// gcc workspace/6.c -lpulse -o 6.exe
// ./6.exe

int main() {
    // double a = pa_sw_volume_to_dB(pa_sw_volume_from_linear(0.75));
    // double b = pa_sw_volume_to_dB(pa_sw_volume_from_linear(0.25));
    // double a = pa_sw_volume_to_dB(75);
    // double b = pa_sw_volume_to_dB(25);
    double a = pa_sw_volume_to_dB(PA_VOLUME_NORM * 75 / 100);
    double b = pa_sw_volume_to_dB(PA_VOLUME_NORM * 25 / 100);
    printf("a: %f, b: %f, a - b: %f:\n", a, b, a - b);
}
