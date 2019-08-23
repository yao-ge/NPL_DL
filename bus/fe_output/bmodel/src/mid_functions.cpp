/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "bmodel.h"

void _BModel::update_mid__egress_pkt__l4_hdr__udp() {
    if (egress_pkt->l4_hdr->udp->_PRESENT == 1) {
        egress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l4_hdr() {
    if (ingress_pkt->l4_hdr->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__payload() {
    if (ingress_pkt->payload->pss[0]->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 3) = 1;
    }
    if (ingress_pkt->payload->pss[1]->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 4) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l3_hdr() {
    if (ingress_pkt->l3_hdr->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__ingress_pkt() {
    if (ingress_pkt->payload->pss[0]->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 3) = 1;
    }
    if (ingress_pkt->payload->pss[1]->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 4) = 1;
    }
    if (ingress_pkt->l4_hdr->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
    if (ingress_pkt->l3_hdr->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
    if (ingress_pkt->l2_hdr->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l2_hdr() {
    if (ingress_pkt->l2_hdr->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__payload__pss___1___() {
    if (ingress_pkt->payload->pss[1]->_PRESENT == 1) {
        ingress_pkt->_match_id(4, 4) = 1;
    }
}

void _BModel::update_mid__egress_pkt__payload() {
    if (egress_pkt->payload->pss[1]->_PRESENT == 1) {
        egress_pkt->_match_id(4, 4) = 1;
    }
    if (egress_pkt->payload->pss[0]->_PRESENT == 1) {
        egress_pkt->_match_id(3, 3) = 1;
    }
}

void _BModel::update_mid__egress_pkt__l4_hdr() {
    if (egress_pkt->l4_hdr->udp->_PRESENT == 1) {
        egress_pkt->_match_id(2, 2) = 1;
    }
}

void _BModel::update_mid__egress_pkt__l2_hdr__l2() {
    if (egress_pkt->l2_hdr->l2->_PRESENT == 1) {
        egress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__egress_pkt__l2_hdr() {
    if (egress_pkt->l2_hdr->l2->_PRESENT == 1) {
        egress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__egress_pkt__l3_hdr() {
    if (egress_pkt->l3_hdr->ipv4->_PRESENT == 1) {
        egress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__egress_pkt() {
    if (egress_pkt->payload->pss[1]->_PRESENT == 1) {
        egress_pkt->_match_id(4, 4) = 1;
    }
    if (egress_pkt->payload->pss[0]->_PRESENT == 1) {
        egress_pkt->_match_id(3, 3) = 1;
    }
    if (egress_pkt->l4_hdr->udp->_PRESENT == 1) {
        egress_pkt->_match_id(2, 2) = 1;
    }
    if (egress_pkt->l3_hdr->ipv4->_PRESENT == 1) {
        egress_pkt->_match_id(1, 1) = 1;
    }
    if (egress_pkt->l2_hdr->l2->_PRESENT == 1) {
        egress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l2_hdr__l2() {
    if (ingress_pkt->l2_hdr->l2->_PRESENT == 1) {
        ingress_pkt->_match_id(0, 0) = 1;
    }
}

void _BModel::update_mid__egress_pkt__payload__pss___0___() {
    if (egress_pkt->payload->pss[0]->_PRESENT == 1) {
        egress_pkt->_match_id(3, 3) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__payload__pss___0___() {
    if (ingress_pkt->payload->pss[0]->_PRESENT == 1) {
        ingress_pkt->_match_id(3, 3) = 1;
    }
}

void _BModel::update_mid__egress_pkt__l3_hdr__ipv4() {
    if (egress_pkt->l3_hdr->ipv4->_PRESENT == 1) {
        egress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__egress_pkt__payload__pss___1___() {
    if (egress_pkt->payload->pss[1]->_PRESENT == 1) {
        egress_pkt->_match_id(4, 4) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l3_hdr__ipv4() {
    if (ingress_pkt->l3_hdr->ipv4->_PRESENT == 1) {
        ingress_pkt->_match_id(1, 1) = 1;
    }
}

void _BModel::update_mid__ingress_pkt__l4_hdr__udp() {
    if (ingress_pkt->l4_hdr->udp->_PRESENT == 1) {
        ingress_pkt->_match_id(2, 2) = 1;
    }
}

