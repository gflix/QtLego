# QtLego

## Purpose

The main purpose of this tool is just to have some fun and discover the abilities of LEGO's Bluetooth enabled devices.

This tool does not aim to implement the whole protocol (aka LEGO Wireless Protocol, LWP) as specified in https://lego.github.io/lego-ble-wireless-protocol-docs . As the official documentation was not updated for a long time, devices like the Technic hub and Super Mario are not yet documented there.

Anyway obvious functions have been reverse engineered and made available but may be subject to changes without notice.

## Project structure

Project is divided into four parts:

* UI related stuff,
* Basic Bluetooth related functions (discovery, connection handling),
* LEGO Wireless Protocol,
* Unit tests

The LEGO Wireless Protocol is implemented as a set of models and protocols to decode and encode the various kinds of messages. Any message gets decoded through decodeLeMessage() which on success returns a shared pointer with the specific model of the decoded message. The shared pointer can be dynamically casted to retrieve the decoded payload.

In a later step the protocol implementation may be moved into a separate library which could be reused within a different project.

## Tested devices

The tool was tested with the following devices:

* Technic hub (bb0961c01),
* Boost hub (bb0894c01),
* Mario figure (49242c01pb001)
