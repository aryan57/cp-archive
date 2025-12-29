FROM ubuntu:24.04

# Set for non interactive debian build installs
ARG DEBIAN_FRONTEND=noninteractive

# Update and install tools
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    gdb \
    vim \
    git \
    nano \
    neofetch \
    htop \
    btop \
    bat \
    curl \
    wget \
    zsh \
    iputils-ping \
    traceroute \
    sudo \
    openssh-server \
    && rm -rf /var/lib/apt/lists/*

# Fix for 'bat' naming in Ubuntu
RUN ln -s /usr/bin/batcat /usr/local/bin/bat

# Create user 'aryan', set default shell to zsh (-s), and password to '0'
RUN useradd -m -s /bin/zsh aryan && \
    echo "aryan:0" | chpasswd && \
    usermod -aG sudo aryan

RUN mkdir /var/run/sshd

# Install Oh My Zsh for user 'aryan'
USER aryan
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended

# Configuration updates via sed
# 1. Set theme to gnzh
RUN sed -i 's/^ZSH_THEME=.*/ZSH_THEME="gnzh"/' ~/.zshrc

# 2. Disable the Oh My Zsh update prompt (prevents interactive popups)
RUN sed -i 's/^# DISABLE_UPDATE_PROMPT=.*/DISABLE_UPDATE_PROMPT="true"/' ~/.zshrc

USER root
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
