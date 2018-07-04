## Wisol WSSFM10R Sigfox Breakout Board

- Autodesk EAGLE board and schematic for Wisol WSSFM10R2/4 Sigfox Breakout board (Sigfox Zones RCZ2 and RCZ4) are in `Wisol-Breakout.brd` and `Wisol-Breakout.sch`

- The PCB design uses 4 layers. If you're using the Free Edition of Autodesk EAGLE, you will only see the top and bottom layers.
  Subscribe to the Standard Edition of Autodesk EAGLE to see all 4 layers.

- Formatted for Seeed Fusion PCB Assembly service: <br>
  https://www.seeedstudio.com/fusion.html

- All components sourced from Seeed Open Parts Library, except for Wisol module: <br>
  https://www.seeedstudio.com/opl.html

- PCB layout was validated in Autodesk EAGLE with the Seeed Fusion Design Rules `SeeedStudio_4layer_DRU_no_angle_20140221.dru`

- PCB design was exported from Autodesk EAGLE to Seeed Fusion in Gerber RS-274x and Excellon (drill) formats using the CAM Processor `Seeed_Gerber_Generater_4-layer_1-2-15-16.cam`

## Seeed Fusion PCB Manufacturing and Assembly

Order submitted to Seeed Fusion for PCB manufacturing and assembly at https://www.seeedstudio.com/fusion_pcb.html:

1. `Wisol-Breakout_2018-xx-xx.zip`: PCB design in Gerber RS-274x and Excellon (drill) formats

1. PCB Specifications: <br>
  PCB Dimensions - 25.4mm*21.6mm <br>
  Impedance Control - No <br>
  Surface Finish - HASL <br>
  Minimum Solder Mask Dam - 0.4mm↑ <br>
  Copper Weight - 1oz. <br>
  Plated Half-holes / Castellated Holes - No <br>
  Minimum Drill Hole Size - 0.3mm <br>
  PCB Color - Green <br>
  Base Material - FR-4 TG130 <br>
  No. of Layers - 4 layers <br>
  Blind or Buried Vias - No <br>
  PCB Thickness - 1.6 <br>
  Trace Width / Spacing - 4/4 mil <br>
  No. of Different Designs - 1 <br>

1. `Wisol-Breakout-BOM.csv`: Bill Of Materials (BOM) for Sigfox Zone RCZ4. Update the WSSFM10R Manufacturer Part Number (MPN) in the BOM if you are in other zones: <br>
  For RCZ1: WSSFM10R1AT<br>
  For RCZ2: WSSFM10R2AT<br>
  For RCZ3: WSSFM10R3AT<br>
  For RCZ4: WSSFM10R4AT<br>

1. Link provided to Seeed Fusion for sourcing WSSFM10R4AT (RCZ4): <br>																									
  https://www.avnet.com/shop/apac/products/wisol/wssfm10r4at-3074457345633583729/?aka_re=1																							

## Changes for Sigfox Zones RCZ1 and RCZ3

The design here was created for Wisol WSSFM10R2 and R4 (Sigfox Zones RCZ2 and RCZ4). For Wisol WSSFM10R1 and R3 (Sigfox Zones RCZ1 and RCZ3) the footprint is smaller and the module needs to be moved down by 5mm.  All other pins and components are unchanged.

![Wisol WSSFM10R Placement](https://raw.githubusercontent.com/lupyuen/Wisol-WSSFM10R-Sigfox-Breakout/master/Hardware/Wisol-Footprint.png)

## References

1. Original PCB design by Sea Slug Labs: <br>
  https://github.com/SeaSlugLabs/Wisol-WSSFM10R2-Sigfox-Breakout
  
1. List of all Sigfox Zones and the countries covered: <br>
  http://makers.sigfox.com/about/

1. Wisol WSSFM10R H/W Design Guide R03 170320

1. Wisol WSSFM10R4AT Datasheet REV02 170320

![Wisol WSSFM10R2/4 Sigfox Breakout board](https://raw.githubusercontent.com/lupyuen/Wisol-WSSFM10R-Sigfox-Breakout/master/Hardware/PCB.png)
