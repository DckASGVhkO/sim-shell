FROM ubuntu:latest

ARG USERNAME=vscode
RUN apt-get update && \
    apt-get install -y python3 python3-pip && \
    useradd -ms /bin/bash $USERNAME

USER $USERNAME

WORKDIR /home/vscode
