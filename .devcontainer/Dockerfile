FROM ubuntu:latest

ARG USERNAME=vscode

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y sudo python3 python3-pip git && \
    useradd -m $USERNAME && \
    echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER $USERNAME
