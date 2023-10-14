import board
import digitalio
import neopixel


class PlayGroundExpress(object):
    PIXEL_PIN = board.D8
    NUM_PIXELS = 10

    SWITCH_PIN = board.D7

    def __init__(self):
        self._pixels = neopixel.NeoPixel(self.PIXEL_PIN, self.NUM_PIXELS, brightness=1,
                                         auto_write=True)
        self._switch = digitalio.DigitalInOut(self.SWITCH_PIN)

    @property
    def pixels(self):
        return self._pixels

    @property
    def switch(self):
        return self._switch

    @property
    def temperature_sensor(self):
