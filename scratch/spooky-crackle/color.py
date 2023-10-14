import asyncio
import random

import adafruit_fancyled.adafruit_fancyled as fancy
from neopixel import NeoPixel

levels = (0.25, 0.3, 0.15)
gammas = (2.6, 2.6, 2.7)


def _adjust(red, green, blue):
    return fancy.gamma_adjust(fancy.CRGB(red, green, blue), brightness=levels,
                              gamma_value=gammas).pack()


RED = _adjust(255, 0, 0)
YELLOW = _adjust(255, 150, 0)
GREEN = _adjust(0, 255, 0)
CYAN = _adjust(0, 255, 255)
BLUE = _adjust(0, 0, 255)
PURPLE = _adjust(180, 0, 255)
ORANGE = _adjust(255, 87, 51)


def random_color():
    return _adjust(
        random.randint(0, 255),
        random.randint(0, 255),
        random.randint(0, 255)
    )


def jitter(value: float, scale: float):
    scale_adjust = random.random() * 2 - 1
    return value + (scale * scale_adjust)


async def pulse(pixel: NeoPixel, cycle_time: int, num_steps: int, min_brightness=0,
                max_brightness=1):
    step_size = max_brightness - min_brightness / num_steps
    sleep_time = cycle_time * 2 / num_steps
    direction = 1

    def _cap(target):
        if direction == 1:
            return min(target, max_brightness)
        return max(target, min_brightness)

    while True:
        current = pixel.brightness
        if current == max_brightness:
            direction = 1
        elif current == min_brightness:
            direction = -1

        target = current + (step_size * direction)
        pixel.brightness = _cap(target)
        await asyncio.sleep(sleep_time)
