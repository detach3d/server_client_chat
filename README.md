# Interactive Server-Client Communication

This project provides a simple C++ server-client application for Linux that allows interactive message exchange. The server listens for incoming connections, and the client sends messages to the server. The interaction is done in real-time, with the server displaying messages it receives from the client.

## Technologies Used

- **C++**: The application is written in C++.
- **Linux**: The project is designed to run on a Linux-based system.

## Prerequisites

To run this project, ensure you have:

- A C++ compiler (e.g., `g++`).
- A Linux-based system (or WSL on Windows).
- Basic knowledge of compiling and running C++ programs in Linux.

## Getting Started

Follow these steps to set up and run the server and client:

### 1. Run the Server

Start the server by running:

```bash
./server 127.0.0.1 8080
```

The server will begin listening on `127.0.0.1` (localhost) at port `8080`.

### 2. Run the Client

Run the client to connect to the server:

```bash
./client 127.0.0.1 8080
```

The client will prompt you to enter messages, which it will send to the server.

## Usage

- The **server** listens for incoming client connections on `127.0.0.1:8080`.
- The **client** sends interactive messages to the server.
- The **server** displays the received messages in the terminal.

### Example Interaction

1. **Server Output**:

   ```
   server received 'Hello, server!'
   server received 'How are you?'
   ```

2. **Client Prompt**:

   ```
   Hello, server!
   How are you?
   ```

