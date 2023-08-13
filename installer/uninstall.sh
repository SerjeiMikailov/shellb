if [ "$1" == "--uninstall" ]; then
    
    read -p "Are you sure you want to uninstall? (y/n): " confirm
    if [ "$confirm" == "y" ]; then
        echo "Uninstalling..."
        
        pkill shellb

        cd $HOME

        rm -rf shellbsrc

        cd /usr/local/bin/

        sudo rm -rf shellb
        sudo rm -rf updateshellb.sh
        sudo rm -rf uninstall.sh

        rm -rf "$0"
        
        echo "Uninstallation complete."
    else
        echo "Uninstallation canceled."
    fi
fi
