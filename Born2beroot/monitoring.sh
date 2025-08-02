#!/bin/bash

# システムのアーキテクチャやカーネルのバージョン
cmd_arch=$(uname -a)
printf "#Architecture: %s\n" "$cmd_arch"

# 物理CPUの数
cmd_cpu_phys=$(lscpu | awk -F: '/^Socket\(s\)/{gsub(/^ *| *$/,"",$2); print $2}')
printf "#CPU physical: %s\n" "$cmd_cpu_phys"

# 仮想CPUの数
cmd_vcpu=$(nproc)
printf "#vCPU: %s\n" "$cmd_vcpu"

# メモリ使用量
mem_used=$(free -m | awk '/^Mem:/ {print $3}')
mem_total=$(free -m | awk '/^Mem:/ {print $2}')
if [ "$mem_total" -ne 0 ]; then
    mem_percent=$(echo "scale=2; ($mem_used / $mem_total) * 100" | bc -l)
else
    mem_percent="0.00"
fi
printf "#Memory Usage: %s/%sMB (%.2f%%)\n" "$mem_used" "$mem_total" "$mem_percent"

# ディスう使用量
disk_info_line=$(df -BG --total | awk 'END{print}')
disk_used=$(echo "$disk_info_line" | awk '{print $3}' | sed 's/G//')
disk_total=$(echo "$disk_info_line" | awk '{print $2}' | sed 's/G//')
disk_percent=$(echo "$disk_info_line" | awk '{print $5}' | sed 's/%//')
printf "#Disk Usage: %s/%sGb (%s%%)\n" "$disk_used" "$disk_total" "$disk_percent"

# CPUの負荷
cpu_idle_percent=$(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/")
if [[ "$cpu_idle_percent" =~ ^[0-9.]+$ ]]; then
    cpu_load_percent=$(echo "scale=1; 100 - $cpu_idle_percent" | bc -l)
else
    cpu_load_percent="N/A"
fi
printf "#CPU load: %s%%\n" "$cpu_load_percent"

# 最後に起動した日時
cmd_last_boot=$(who -b | awk '{print $3 " " $4}')
printf "#Last boot: %s\n" "$cmd_last_boot"

# LVM使用状況
printf "#LVM use: "
if lsblk | grep -q "lvm"; then
    printf "yes\n"
else
    printf "no\n"
fi

# TCPの接続数
cmd_tcp_connections=$(ss -Htn state ESTABLISHED | wc -l)
printf "#Connections TCP: %s ESTABLISHED\n" "$cmd_tcp_connections"

# ログインしているユーザー数
cmd_user_log=$(users | wc -w)
printf "#User log: %s\n" "$cmd_user_log"

# サーバーのIPアドレスとMACアドレス
default_iface=$(ip route | awk '/default via/ {print $5; exit}')
ipv4_address="N/A"
mac_address="N/A"
if [ -n "$default_iface" ]; then
    ipv4_address_full=$(ip -4 addr show "$default_iface" | grep -oP 'inet \K[\d.]+/\d+' || echo "N/A/0")
    ipv4_address=$(echo "$ipv4_address_full" | cut -d/ -f1)
    mac_address=$(ip link show "$default_iface" | awk '/ether/ {print $2}' || echo "N/A")
fi
printf "#Network: IP %s (%s)\n" "${ipv4_address}" "${mac_address}"

# sudoが実行されたコマンドの数
sudo_cmd_count="0"
if [ -r "/var/log/sudo/seq" ]; then
    sudo_cmd_count_raw=$(cat /var/log/sudo/seq)
    if [[ "$sudo_cmd_count_raw" =~ ^[0-9A-Za-z]+$ ]]; then
        sudo_cmd_count=$(echo "obase=10; ibase=36; $sudo_cmd_count_raw" | bc)
    fi
fi
printf "#Sudo: %s cmd\n" "$sudo_cmd_count"
