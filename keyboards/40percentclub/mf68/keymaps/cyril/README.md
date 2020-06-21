**Bootloader configuration info (config.h):**  
- k00 \[Esc\] as dfu-escape key  
- k14 \[Backspace\] as plug-to-bootloader key  

Flash qmk-dfu:  
`avrdude -c usbasp -p m32u4 -P usb -e -U lock:w:0x3F:m -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m`  
`avrdude -c usbasp -p m32u4 -P usb -D -U flash:w:"40percentclub_mf68_cyril_production.hex":a`  

## A custom-pcb keyboard project using the MagicForce 68 layout
Powered by a "pro micro" atmega32u4

![Imgur](https://i.imgur.com/CJMMnIm.jpg)

Originally covered (thoroughly) by [40percent.club](http://www.40percent.club/search?q=mf68) and [68keys.io](http://www.68keys.io)  
I only attempted this because the project was so well documented by the aforementioned sources.

Main Goal:  
A fully-programmable keyboard with a layout just fat-enough to suit (my) 3D CAD-life without requiring much of a change of habits, because I will still need to work at standard ansi 104-key consoles. 

Benefits of layout:  
- Allows the overall reduction of keyboard real-estate, without trodding heavily upon existing muscle-memory habits.
  - Number-pad? Either ditch it completely, or use a separate one in a better location (NOT in-between the mouse and alpha-keys).
  - Dedicated f-keys are not necessary; functionality can be relocated to a sub-layer of the number-keys with minimal impact to current f-key habits/usage
  - Scroll Lock and Print-screen? burn-em.   okay fine, \[fn\]+\[p\] for print-screen
- Retains the tactile usefulness of ansi-layout cluster-spacing 
  - I am not a fan of the smashed arrangements of 65/75 percent keebs that lack any spacing in-between the alpha, arrow, & f-key clusters.
  - Admittedly, the 60% layout does not benefit from such tactile usefulness, since the other clusters are implemented as layered keys. 

Build differences:  
- Breakout-board instead of integrated USB port
  - Contributes to lower overall-height of keyboard
  - Makes broken/damaged ports a small issue.
- Pro-micro mounted in-between pcb and switch-plate (on-board micro-usb removed)
  - Contributes to lower overall-height of keyboard
  - More labor involved if access is required

Other thoughts:  
- I am slowly temped into keymap-tweaks that make too much sense to ignore:  
  `\[shift\]+\[backspace\]=\[del\]`
  `\[fn\]+\[shift\]=\[Caps Lock\]`  
  `\[Caps Lock\]=\[L_Ctrl\]`  
- The single-plate build is specifically aimed at a low keyboard height; the height of the switch & keycap define the minimun possible height.  
  The top of the switch plate is ~10mm from the surface. Is this useful? Maybe, maybe not.
- 60 percent is VERY tempting, but requires the layering of often-used keys, resulting in keystroke-habits that are likely to trip me up at more-standard ansi keyboards. This 65% setup only layers less-used keys, easing the transition.  
I will likely switch to a 60% at home, but doubt that it will do well for me at work.

![Imgur](https://i.imgur.com/vLh8oCs.jpg)

![Imgur](https://i.imgur.com/fC9FlJY.jpg)

![Imgur](https://i.imgur.com/iEbbEUt.jpg)
