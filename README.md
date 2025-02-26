# Intelligent Street Lighting System  

### Adaptive, Energy-Efficient, and Smart  

This project presents an **Intelligent Street Lighting System** that dynamically adjusts brightness based on movement detection. Unlike traditional street lights that remain static or dim at pre-set intervals, our system responds to pedestrians, cyclists, and vehicles in real-time. Our prototype ensures efficient energy consumption while enhancing safety by leveraging **Arduino** and **various sensors**.  

---

##  Features  

- **Motion-Activated Brightness** – Lights brighten when motion is detected.  
- **Autonomous Light Distribution** – The system **activates the next two street lights** ahead for seamless illumination.  
- **Energy Efficiency** – Lights return to their dim state once no movement is detected.  
- **Interconnected System** – Lights communicate to provide continuous visibility.  

---

##  How It Works  

1. **Default State**: The first street light remains dim when it's dark.  
2. **Motion Detection**: Sensors detect movement and increase brightness.  
3. **Sequential Lighting**: The system **activates the next two street lights** ahead.  
4. **Auto Reset**: Lights dim again once no movement is detected.  

---

##  Components  

| Component | Function |
|-----------|----------|
| **LDR (Light Dependent Resistor)** | Detects ambient light levels. |
| **IR Sensors** | Detects motion from pedestrians, vehicles, or cyclists. |
| **LEDs (Light Emitting Diodes)** | Simulates streetlights with adjustable brightness. |
| **Arduino** | Controls the system based on sensor inputs. |
| **Breadboard & Wires** | Used for circuit connections. |
| **LM393 Speed Sensor** | Enhances motion detection accuracy. |


