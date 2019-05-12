# SW102_Bootloader
Bootloader based on nrf5 secure bootloader example ported to SW102

### Getting started with Nordic's Secure DFU bootloader
* [A step by step guide](https://devzone.nordicsemi.com/b/blog/posts/getting-started-with-nordics-secure-dfu-bootloader) from the Nordic DevZone Blog for further reading.
* [The Nordic secure bootloader example](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.sdk5.v12.3.0%2Fble_sdk_app_dfu_bootloader.html) from SDK12.3.0
* [nrf5 SDK 12.3.0 bootloader library](https://infocenter.nordicsemi.com/topic/com.nordic.infocenter.sdk5.v12.3.0/lib_bootloader.html)

### HowTo Generate DFU .zip packet
* For DFU packet generation we use the Nordic command line tool ***nrfutil***. It is a Python-based, so you need to:
* Install [Python 2](https://www.python.org/downloads/release/python-2716/) with pip. See [here](http://stackoverflow.com/a/23192051) if you don't have pip with Python. Make also sure that the Python installation is in your path.
* Install [nrfutil](https://github.com/NordicSemiconductor/pc-nrfutil) from python using ***pip install nrfutil***. To check for update, call ***pip install nrfutil --upgrade***.
* It is also a [precompiled Windows executable](https://github.com/NordicSemiconductor/pc-nrfutil#downloading-precompiled-windows-executable) available, then you don't need to install Python ;).
* For creating a firmware update package, we use the command:
```
nrfutil pkg generate --application PATH_TO_HEX_FILE --key-file PATH_TO_PRIVATE_KEY --application-version 1 --hw-version 51 --sd-req 0x87 update_firmware.zip
```
* For an explanation of the command line parameters, see ***Step C. Generate DFU .zip packet.*** in Nordics step by step guide.
* For the acceptance rules for versions, please see the [Nordic SDK documentation](https://infocenter.nordicsemi.com/topic/com.nordic.infocenter.sdk5.v12.3.0/ble_sdk_app_dfu_bootloader.html?cp=5_4_7_4_3_1_3_1#lib_bootloader_dfu_init_validation_acceptance_rules).
