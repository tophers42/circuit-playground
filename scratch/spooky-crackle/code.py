"""CircuitPython Essentials NeoPixel example"""
import asyncio

from .color import pulse
from .playground_express import PlayGroundExpress

x = PlayGroundExpress()


def on_toggle(value: bool, current_task):
    if value:
        if current_task is not None:
            return current_task
        return asyncio.create_task(pulse(pixel=x.pixels, cycle_time=5, num_steps=50))
    if current_task is not None:
        current_task.cancel()
    return None


async def main():
    watch_switch_task = x.watch_switch(on_toggle=on_toggle)
    await asyncio.gather(watch_switch_task)
    print("done")


asyncio.run(main())
