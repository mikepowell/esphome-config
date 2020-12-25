<!-- markdownlint-disable MD041 -->
| Repository Status | ESPHome Community |
| :--- | :--- |
| [![last commit time][github-last-commit]][github-master] [![GitHub Activity][commits-shield]][commits] | [![Discord][discord-shield]][discord] [![Community Forum][discourse-shield]][discourse]  |

# My ESPHome Devices

Configuration files for my ESP8266 / ESP32 plugs and boards for use with Home Assistant.
I have made heavy use of `!include` files to limit code duplication. This allows me to
focus on the advanced code I create for projects like my Bathroom Fan Controller and my
Irrigation Controller.

## Common configuration files

### /common/

In the common folder you will find repetitive configuration blocks representing status
light, wifi, api, and logging. The Sonoff and Tuya Plugs share common code in the
`/common/templates/` folder. @AlexMekkering thank you for
[showing us how powerful this is][config-includes].

## Devices

### bluetooth_hub.yaml

I started with the [ESP32 Bluetooth Low Energy Tracker Hub][esphome-ble-hub] example
on esphome.io, and added Xiaomi temperature plant sensors.

### Standard plugs: plug01.yaml - plug03.yaml

### ZooZee brand Tuya plugs

These are simple round wall plug were flashed with over the air with tasmota-convert,
then ESPHome was uploaded via the Tasmota UI. The ESPHome code attempts to recreate
their original functionality.

### Hot Water Pump: plug05.yaml

This plug controls the whole house hot water recirculation pump. When we turn this
on we don't want it to keep running forever. So I set a timeout that turns the pump
off after 10 minutes. This timeout is a backup to the Home Assistant automation that
automatically turns it off after 5 minutes.

### Standard plugs: plug04.yaml - plug07.yaml

#### Luntak brand Tuya plugs

These are simple round wall plugs were flashed with over the air with tasmota-convert,
then ESPHome was uploaded via the Tasmota UI. The ESPHome code attempts to recreate their
original functionality.

### Shelly1's

These devices are great for shoving in a box behind a light switch to add smarts.

#### Dining Room Wall Switch: shelly1_01.yaml

I coded this to be create a smart switch that is compatible with a chandelier with 9 hue
bulbs. Its relay is disabled, unless Home Assistant is unavailable. This allows it to operate
as a virtual 3-way switch with Home Assistant, as well as failing gracefully should Home
Assistant be offline to act as a dumb toggle switch.

#### Upstairs Bathroom Fan: shelly1_02.yaml

This allows users to manually turn on or off the fan. If they turn it on while the humidity
is below 65% then it will turn off after 15 minutes. If the humidity is above 65% when the
manual switch is turned on, it will start a 60 minute timer which will absolutely turn the
fan off at that time.

The ESPHome code gets the humidity from Home Assistant and handles all automations internally.
When the humidity goes above 65% it automatically turns on, until the humidity falls below 65%.

The switch will also fail gracefully when Home Assistant is not available to act as a dumb
toggle switch.

### Standard plugs: sonoff_basic_01.yaml, sonoff_basic_02.yaml

These are [Sonoff Basics][esphome-sonoff-basic], with plugs on either side. One is used to
switch on a floor fan, and the other is being reserved possibly to control a bathroom vent fan.

### Power monitoring ONLY plugs: sonoff_s31_01.yaml, sonoff_s31_02.yaml

These are Sonoff S31 plugs are set to power on a boot, their physical "power" push buttons are
disabled, and the virtual button hidden from Home Assistant. They are being used to monitor
the power usage of a clothes washing machine and my wife's Glowforge laser cutter. With this
data, I can create automations markto alert us when the wash cycle or the laser cycle is complete.

### Power monitoring plugs: sonoff_pow_01.yaml, sonoff_pow_02.yaml, sonoff_s31_03.yaml - sonoff_s31_06.yaml

These are Sonoff POWs and Sonoff S31s. The code attempts to recreate their functionality.

[commits-shield]: https://img.shields.io/github/commit-activity/m/brianhanifin/esphome-config.svg
[commits]: https://github.com/brianhanifin/esphome-config/commits/master
[github-last-commit]: https://img.shields.io/github/last-commit/BrianHanifin/esphome-config.svg?style=plasticr
[github-master]: https://github.com/BrianHanifin/esphome-config/commits/master
[discord-shield]: https://img.shields.io/discord/330944238910963714.svg?logo=discord&color=7289da
[discord]: https://discord.gg/A7SaaSC
[discourse-shield]: https://img.shields.io/discourse/topics?color=46B4ED&label=community&logo=discourse&logoColor=46B4ED&server=https%3A%2F%2Fcommunity.home-assistant.io
[discourse]: https://community.home-assistant.io/u/brianhanifin/summary

[esphome-ble-hub]:https://esphome.io/components/esp32_ble_tracker.html
[esphome-sonoff4pro]:https://esphome.io/devices/sonoff_4ch.html
[esphome-sonoff-basic]:https://esphome.io/devices/sonoff_basic.html
[esphome-examples]:https://esphome.io/guides/diy.html
[config-includes]:https://github.com/AlexMekkering/esphome-config
[irrigation-with-display]:https://github.com/bruxy70/Irrigation-with-display
