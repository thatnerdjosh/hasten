FROM registry.access.redhat.com/ubi9/toolbox:latest

# Add VSCode Repo/install
RUN rpm --import https://packages.microsoft.com/keys/microsoft.asc && \
    sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo' && \
    dnf -y install code

# Dev Tools
RUN dnf -y install vim tmux make gcc

# Libraries
RUN dnf -y install SDL2-devel mesa-dri-drivers
    
