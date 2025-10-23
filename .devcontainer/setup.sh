#!/bin/bash

USERNAME=${1:-aryan}

# Update package lists
sudo apt-get update

sudo apt-get install -y build-essential g++ gcc gdb vim git nano neofetch htop curl wget

# Clean up
sudo apt-get clean
sudo rm -rf /var/lib/apt/lists/*

# Configure Oh My Zsh theme
sed -i 's/ZSH_THEME=".*"/ZSH_THEME="gnzh"/' /home/$USERNAME/.zshrc

# Fix ownership
# make the user owner and group owner of the home directory recursively
chown -R $USERNAME:$USERNAME /home/$USERNAME
