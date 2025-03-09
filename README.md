# Interactive Server-Client Communication

This project provides a simple C++ server-client application for Linux that allows interactive message exchange. The server listens for incoming connections, and the client sends messages to the server. The interaction is done in real-time, with the server displaying messages it receives from the client.

## Technologies Used

- **C++**: The application is written in C++.
- **Linux**: The project is designed to run on a Linux-based system.

## Getting Started

Follow these steps to set up and run the server and client:

### 1. Run the Server

Start the server by running:

```bash
./server localhost 1234
```

The server will begin listening on `127.0.0.1` (localhost) at port `1234`.

### 2. Run the Client

Run the client to connect to the server:

```bash
./client localhost 1234
```

The client will prompt you to enter messages, which it will send to the server.

## Usage

- The **server** listens for incoming client connections on `127.0.0.1:1234`.
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

