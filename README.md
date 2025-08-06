# minitalk - Inter-Process Communication via Signals

## About

**minitalk** is a systems programming project at École 42 that explores inter-process communication (IPC) using Unix signals. The project involves creating a client-server communication system where the client transmits strings to the server using only `SIGUSR1` and `SIGUSR2` signals. This project demonstrates advanced understanding of Unix signals, process management, and binary data transmission.

The implementation showcases low-level system programming concepts while creating a functional communication protocol using minimal system resources. The project emphasizes signal handling, process synchronization, and efficient binary encoding techniques.

## Learning Objectives

- **Signal Handling**: Mastering Unix signal mechanisms and custom signal handlers
- **Inter-Process Communication**: Understanding IPC methods and their applications
- **Binary Data Transmission**: Converting data to binary format for signal-based communication
- **Process Synchronization**: Coordinating between multiple processes safely
- **System Programming**: Working with process IDs, signal queuing, and timing
- **Protocol Design**: Creating efficient communication protocols with limited resources
- **Error Handling**: Robust signal handling and process management

## Project Components

### Server Program
The server program establishes a communication endpoint that:
- Displays its Process ID (PID) upon startup
- Listens for incoming signals from clients
- Reconstructs messages from binary signal sequences
- Displays received messages to standard output
- Handles multiple client connections sequentially
- Sends acknowledgment signals back to clients (bonus)

### Client Program
The client program initiates communication by:
- Taking server PID and message as command-line arguments
- Converting message characters to binary representation
- Transmitting each bit as either SIGUSR1 (0) or SIGUSR2 (1)
- Managing signal transmission timing and synchronization
- Receiving acknowledgment signals from server (bonus)
- Handling transmission errors and retries (bonus)

## Signal-Based Communication Protocol

### Basic Protocol (Mandatory)
The communication uses a simple binary encoding scheme:
- **SIGUSR1**: Represents binary bit '0'
- **SIGUSR2**: Represents binary bit '1'
- Each character is transmitted as 8 bits (MSB first)
- Null terminator signals end of message

### Enhanced Protocol (Bonus)
The bonus implementation adds bidirectional communication:
- Server acknowledgment after each character
- Client confirmation of successful transmission
- Error detection and retransmission capabilities
- Support for Unicode characters
- Optimized signal handling for faster transmission

## Implementation Details

### Binary Encoding Strategy

#### Character to Binary Conversion
Each character undergoes bit-by-bit transmission:
1. Extract each bit using bitwise operations
2. Send most significant bit first
3. Use appropriate signal for each bit value
4. Wait for server acknowledgment before next bit

#### Unicode Support (Bonus)
Extended character support for international text:
- UTF-8 encoding for multi-byte characters
- Variable-length character handling
- Proper byte sequence transmission
- Character boundary detection

### Synchronization Mechanisms

#### Basic Synchronization
- Fixed timing delays between signal transmissions
- Sequential bit transmission without overlap
- Simple acknowledgment system

#### Advanced Synchronization (Bonus)
- Dynamic timing adjustment based on system load
- Signal queuing management to prevent loss
- Retry mechanisms for failed transmissions
- Real-time acknowledgment processing

## Usage Examples

### Basic Server-Client Communication
```bash
# Terminal 1: Start server
./server
# Output: Server PID: 12345

# Terminal 2: Send message from client
./client 12345 "Hello, World!"
# Server displays: Hello, World!
```

### Extended Message Testing
```bash
# Long message transmission
./client 12345 "This is a longer message to test the reliability of signal-based communication."

# Special characters and numbers
./client 12345 "Test: 123!@#$%^&*()_+-=[]{}|;:,.<>?"

# Multi-line message
./client 12345 "Line 1
Line 2
Line 3"
```

### Unicode Support (Bonus)
```bash
# International characters
./client 12345 "Héllo, Wörld! 🌍"

# Various language scripts
./client 12345 "English, Français, Русский, 한국어, Сәлем"
```

### Performance Testing
```bash
# Large message transmission
./client 12345 "$(cat large_text_file.txt)"
```

## Advanced Features (Bonus - 125/100)

### Bidirectional Communication
- **Server Acknowledgments**: Confirmation after each received character
- **Client Confirmation**: Verification of successful message delivery
- **Status Reporting**: Real-time transmission progress indicators

### Enhanced Error Handling
- **Signal Loss Detection**: Timeout mechanisms for lost signals
- **Connection Validation**: PID verification and process existence checking
- **Graceful Degradation**: Fallback mechanisms for communication failure

### Extended Character Support
- **Unicode Transmission**: Full UTF-8 character set support
- **Binary Data**: Support for non-text data transmission
- **Large Messages**: Efficient handling of messages exceeding typical limits

## Compilation and Testing

### Standard Build
```bash
# Compile server and client
make
```

### Bonus Build
```bash
# Compile with bonus features
make bonus
```

## Technical Challenges

### Signal Reliability
Managing signal delivery guarantees and handling potential signal loss in high-load scenarios while maintaining message integrity.

### Process Synchronization
Coordinating multiple processes without race conditions, ensuring proper signal ordering and timing synchronization.

### Memory Management
Efficient buffer management for message reconstruction while handling variable-length messages and preventing memory leaks.

### System Resource Usage
Minimizing system resource consumption while maintaining reliable communication performance.

## Key Challenges & Solutions

### Signal Loss Prevention
- **Challenge**: Signals can be lost or merged in high-frequency transmission
- **Solution**: Acknowledgment-based protocol with retry mechanisms and adaptive timing

### Unicode Character Handling
- **Challenge**: Multi-byte character transmission requires careful byte boundary management
- **Solution**: UTF-8 aware parsing with proper character sequence detection

### Multiple Client Support
- **Challenge**: Handling simultaneous client connections without signal interference
- **Solution**: Client queuing system with process identification and sequential handling

### Performance Optimization
- **Challenge**: Signal-based communication is inherently slower than other IPC methods
- **Solution**: Signal buffering, compression techniques, and optimized bit transmission patterns

## Skills Demonstrated

- **Systems Programming**: Advanced Unix system programming with signals and processes
- **IPC Mastery**: Deep understanding of inter-process communication methods
- **Protocol Design**: Creating efficient communication protocols with resource constraints
- **Binary Data Handling**: Proficiency in bit manipulation and binary encoding
- **Process Management**: Understanding process lifecycle, PIDs, and signal handling
- **Error Recovery**: Implementing robust error handling and recovery mechanisms
- **Performance Engineering**: Optimizing low-level system interactions for efficiency
- **Unicode Processing**: Handling international character sets and encoding standards

## Real-World Applications

The concepts demonstrated in minitalk apply to numerous professional scenarios:
- **Embedded Systems**: Low-bandwidth communication protocols
- **Network Programming**: Understanding of packet-based communication
- **System Administration**: Inter-service communication mechanisms
- **IoT Development**: Resource-constrained communication protocols
- **Real-time Systems**: Signal-based event handling and process coordination

## Notes

The minitalk project demonstrates proficiency in low-level systems programming and showcases understanding of Unix fundamentals that are essential for systems developers. The signal-based communication approach, while unconventional for typical applications, provides excellent learning experience in resource-constrained programming.

---

*Developed as part of the École 42 curriculum - mastering systems programming through innovative inter-process communication implementation.*
