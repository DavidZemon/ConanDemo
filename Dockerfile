FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive \
    TZ=Etc/UTC
RUN apt-get update && apt-get install -y \
    python3-pip \
    cmake \
    make \
    g++ \
    gcc \
    git \
    tree \
    vim
RUN pip3 install conan

WORKDIR /tmp
