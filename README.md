# IS3715 Evaluation Board – Example Code  

This repository contains example code for the evaluation board of the **IS3715** DMX controller IC, as demonstrated in the video:  
🔗 [https://www.youtube.com/watch?v=0Ut7PL3LPDo](https://www.youtube.com/watch?v=0Ut7PL3LPDo)

## Overview  
The evaluation board implements a simple DMX lighting application. Three sliders on the board correspond to DMX channels **1**, **2**, and **3**, which are mapped to control the **Red**, **Green**, and **Blue** components respectively of an RGB DMX fixture.  
As the sliders move, the IS3715 continuously sends DMX data, and the attached RGB light responds in real time.

## IC Characteristics  
- DMX512-A Protocol Compliant  
- Sends All 512 Channels  
- Synchronization Output Pin  
- Update Rate: **44 Hz**

## Advantages  
- Eliminates the complexity of generating a DMX frame with the correct timing requirements.  
- Offloads all DMX protocol handling from the microcontroller, freeing up firmware resources and simplifying code.  
- Ideal for applications that need DMX output without dedicating CPU time to precise protocol timing or low-level DMX implementation.  
- Reduces engineering time and costs.  
- Reduces product time-to-market.  
- Makes the DMX protocol transparent to both the microcontroller and the engineer.  
- Provides a low-cost solution.  
- Fewer ISRs, lower microcontroller CPU load.  
- Reduces microcontroller memory usage.  
- Saves microcontroller dedicated pins with I²C.  
- Minimizes impact on microcontroller peripherals (no need for dedicated timers, UARTs, etc.).  
- Compact, easy-to-solder **SO8N** package.  
- I²C speeds: **100 kHz**, **400 kHz**, and **1 MHz**.

## Applications  
- Custom Lighting Controllers  
- Automated Light Controllers  
- Digital Art Installations  
- Architectural & Building Lighting  
- Stage & Entertainment Lighting  
- Animatronics  
- Water Fountains  
- OEM / Device Manufacturers  
- Museum Lighting  

---

### Resources  
- 🛒 **Buy the chip:** [www.inacks.com/is3715](https://www.inacks.com/is3715)  
- 📄 **Download the Datasheet:** [www.inacks.com/is3715_datasheet_isdoc143](https://www.inacks.com/is3715_datasheet_isdoc143)  
- 💾 **Download this Example Code:** [https://github.com/inacks/ISXMPL3715ex5](https://github.com/inacks/ISXMPL3715ex5)
