#####################################################################
#
# Purpose:
#   To generate traffic for 'bus' construct example.
#
# Steps:
#   Send an IP packet to port-0 of BM.
#      Print hexdump of the transmitted packet.
#
#####################################################################
from scapy.all import *
import os
bm_rpc_lib = os.path.join(os.environ['NCS_ROOT'], 'bmi/cli')
sys.path.append(bm_rpc_lib)
from bm_rpc_intf import *

from datetime import datetime

#Pkt config
dst_mac = "00:00:00:00:01:01"
src_mac = "00:00:00:00:01:01"
dip = "1.2.3.4"
sip = "5.6.7.8"
ihl = 10
ip_len = 108
dataofs = 11

def get_tx_ip_packet(test_num):
    pkt = Ether()/IP()/UDP()/Raw()
    pkt[Ether].dst = dst_mac
    pkt[Ether].src = src_mac
    pkt[IP].dst = dip
    pkt[IP].src = sip
    pkt[IP].ihl = ihl
    #pkt[TCP].dataofs = dataofs
    pkt[Raw].load = "This packet is being sent by test {} from CLI to BM".format(test_num) * 100
    return pkt

if __name__ == '__main__':
    bmintf = BMRpcIntf("10.32.105.222")
    port = [0]

    numpkts = 1
    for count  in range(numpkts):
        for i in port:
            if (count == 0):
                pkt = get_tx_ip_packet(i+1)

            while True:
                recv_pkt = bmintf.tx_pkt(i, pkt, len(str(pkt)))
                break
            print("##################################")
            print("TX PKT on port {}:".format(i))
            #hexdump(pkt)
            if (recv_pkt['STATUS']):
                print("Packet is Dropped!")
            else:
                print("RX PKT on port {}:".format(recv_pkt['PORT']))
                #hexdump(recv_pkt['PACKET'])
###########################################################################
# Example output with above test.
###########################################################################

#xl-sj1-30{sm925758}217: python bm_tests/corp_net/testPkt.py
#WARNING: No route found for IPv6 destination :: (no default route?)
#'Connected to Switch'
###################################
#TX PKT on port 0:
#  0000   00 00 00 00 01 10 00 00  00 00 02 00 08 00 45 00   ..............E.
#  0010   00 5A 00 01 00 00 40 06  6A 8A 05 06 07 08 01 02   .Z....@.j.......
#  0020   03 04 00 14 00 50 00 00  00 00 00 00 00 00 50 02   .....P........P.
#  0030   20 00 66 6C 00 00 54 68  69 73 20 70 61 63 6B 65    .fl..This packe
#  0040   74 20 69 73 20 62 65 69  6E 67 20 73 65 6E 74 20   t is being sent
#  0050   62 79 20 74 65 73 74 20  31 20 66 72 6F 6D 20 43   by test 1 from C
#  0060   4C 49 20 74 6F 20 42 4D                            LI to BM
#  RX PKT on port 0:
#xl-sj1-30{sm925758}218:


###########################################################################
# Snippet from console output on BMODEL
###########################################################################
#Source ip address is 0X5060708
#Destination ip address is 0X1020304
#Source ip address byte 0 is 0X8
#Source ip address byte 1 is 0X7
#Destination ip address byte 0 is 0X4
#Destination ip address byte 1 is 0X3



