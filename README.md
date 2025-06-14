# 🚗 Data-Driven Vehicle Control Using CAN Protocol

An embedded systems project focused on enhancing **vehicle automation and safety** using the **Controller Area Network (CAN) protocol**. This system is divided into three smart nodes that collaboratively monitor and control key vehicle functions such as engine temperature, reverse alert, and window glass positioning.

---

## 🎯 Project Aim

To **display the engine temperature**, provide **reverse obstacle alerts**, and **control door window glass** using real-time data exchanged over the **CAN protocol**.

---

## 📌 Key Features

- 📊 **Engine Temperature Monitoring**
  - Measures engine heat using DS18B20 and displays on an LCD.
- 🛑 **Reverse Obstacle Alert**
  - Uses a GP2D12 IR sensor to detect nearby objects when reversing.
  - Sends alerts to the main controller when within danger range.
- 🪟 **Window Glass Control**
  - Uses switches to open/close windows.
  - LED simulation for glass position feedback (open/close).
- 🔁 **CAN-Based Inter-node Communication**
  - Fast and reliable data transfer using MCP2551 CAN transceivers.
- 📟 **User Interface**
  - LCD display for sensor values and system status.
  - Buzzer and LED alerts for critical events.

---

## 🧱 System Architecture

This system consists of **three independent microcontroller nodes** communicating over a common **CAN Bus**.

### 1. 🧠 Main Node
- Reads and displays temperature via DS18B20.
- Sends commands to the window control node based on switch inputs.
- Receives obstacle alerts from the reverse alert node.
- Manages LCD display and LED/Buzzer alerts.

### 2. 🪟 Window Glass Control Node
- Listens for control signals from the main node.
- Opens or closes the window by lighting up LEDs in sequence (simulating window glass movement).

### 3. 🔙 Reverse Alert Node
- Constantly monitors the distance using the GP2D12 sensor.
- Sends a logic '1' if an obstacle is detected within a predefined threshold, else sends logic '0'.

---

## 🔧 Hardware Requirements

| Component                 | Purpose                                      |
|---------------------------|----------------------------------------------|
| LPC2129 Microcontroller   | Central processing unit                      |
| MCP2551 CAN Transceiver   | CAN communication interface                  |
| DS18B20 Temp Sensor       | Measures engine temperature                  |
| GP2D12 IR Sensor          | Detects object distance for reverse alerts   |
| LCD Display (16x2)        | Displays temperature, alerts, and messages   |
| LEDs                      | Simulate window glass movement               |
| Switches (SW, SW1, SW2)   | Used to trigger control actions              |
| USB to UART Converter     | For programming and serial communication     |

---

## 💻 Software Requirements

- **Embedded C** for firmware development
- **Keil µVision** IDE with Keil-C Compiler
- **Flash Magic** for flashing code to microcontroller

---

## 🔄 Implementation Workflow

### Step-by-Step Process:

1. ✅ **LCD Testing**  
   Display character, string, and numeric constants.

2. ✅ **ADC Interface Test**  
   Connect a potentiometer to test analog readings.

3. ✅ **Distance Measurement**  
   Use GP2D12 to measure and display distance on LCD.

4. ✅ **Interrupt Handling**  
   Count external interrupts and show results on LCD.

5. ✅ **Temperature Monitoring**  
   Interface DS18B20 and show temperature in °C.

6. ✅ **CAN Protocol Testing**  
   Verify message transmission between nodes.

7. ✅ **Full Integration**  
   Program each node with final code:
   - Main Node handles logic and communication.
   - Window Node simulates motor control with LEDs.
   - Reverse Node sends obstacle alerts over CAN.

---

## 📡 CAN Communication Overview

- Utilizes **MCP2551** as the CAN transceiver.
- Messages are sent over **CANH** and **CANL** lines.
- Nodes communicate asynchronously and independently.
- Interrupts are used for handling switch inputs efficiently.

---

## 🚀 Running the Project

1. Flash the individual code for each node onto LPC2129 microcontrollers.
2. Wire all nodes to a common CAN bus (with proper termination resistors).
3. Power on the system and test functionality using:
   - Switches for user input.
   - Distance sensor for obstacle simulation.
   - Temperature sensor for heating simulation.
4. Monitor system behavior through LCD, LEDs, and buzzer.

---

## 📝 Conclusion

This project demonstrates a practical and scalable use of **CAN protocol** in vehicles. With real-time responsiveness and modular design, it replicates real-world automotive communication standards and lays the foundation for more complex systems like autonomous vehicle control.

---

## 📸 Future Improvements

- Replace LEDs with real motors for window control
- Add speed and fuel monitoring
- Integrate wireless diagnostics
- Expand to more vehicle subsystems

---

## 🙌 Acknowledgments

Thanks to our mentors, instructors, and embedded systems community for providing technical guidance and support.

---
