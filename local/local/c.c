/*
	group : local
	name : c.c
	srcPath : /home/aryan/cp-workspace/c.c
	url : /home/aryan/cp-workspace/c.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define IP_BUF 32
#define DESTINATION_PORT 32164
#define SOURCE_PORT 6969
#define UDP_PAYLOAD_SIZE 52
#define UDP_PACKET_LEN 1024
#define MAX_TTL 16
#define MAX_BUFF 100
#define MAX_SAME_TTL 3
#define TIMEOUT 1

struct UDP_pseudo_header
{
	uint32_t source_address;	  /* IPv4 address */
	uint32_t destination_address; /* IPv4 address */
	u_int8_t zero;				  /* set to 0, for padding purpose */
	u_int8_t protocol;			  /* 17 for UDP */
	u_int16_t length;			  /* length of UDP header and data */
};

/**
 * copies the first IP address from
 * the hostinfo->h_addr_list and returns 0.
 * Return -1 for errors
 */
int get_ip(char *hostnamebuf, char *ansbuf)
{
	struct hostent *hostinfo = gethostbyname(hostnamebuf);
	if (hostinfo != NULL)
	{
		strcat(ansbuf, inet_ntoa(*((struct in_addr *)*(hostinfo->h_addr_list))));
		return 0;
	}
	return -1;
}

void fill_random_bytes(char *buf, int _size)
{
	for (int i = 0; i < _size; i++)
		buf[i] = 'a' + rand() % 26;
}

void bin(long long n, int numbits)
{
	for (int i=numbits-1; i >=0; i--)
	{
		printf("%lld",(n>>i)&1);
	}
}

unsigned short change_end_16(unsigned short num){
    return ((num&0x00ff)<<8) + ((num&0xff00)>>8);
}

/* Check sum function  */
unsigned short csum(unsigned short *buf, int nwords)
{
	unsigned long sum;
	for (sum = 0; nwords > 0; nwords--,buf++)
	{
		unsigned short num = change_end_16(*buf);
		sum += num;
		sum = (sum >> 16) + (sum & 0xffff);
	}

	sum += (sum >> 16);
	return (unsigned short)(~sum);
}


void fill_ip_header(struct iphdr *ip_header, size_t udp_data_size, const in_addr_t daddr, in_addr_t saddr, char *buffer)
{
	// https://tools.ietf.org/html/rfc791#page-11
	ip_header->version = 4;
	ip_header->ihl = 5; // we are not adding any options or padding
	ip_header->tos = 0; // use normal routines
	ip_header->tot_len = htons(sizeof(struct iphdr) + sizeof(struct udphdr) + udp_data_size);
	ip_header->id = 0; // will be auto filled
	ip_header->frag_off = 0;
	ip_header->protocol = IPPROTO_UDP;
	ip_header->saddr = saddr;
	ip_header->daddr = daddr;
	ip_header->check = 0; // initialised to 0, will be filled after checksum calculation
}

void fill_udp_header(struct udphdr *udp_header, uint16_t destport, uint16_t srcprt, uint16_t len)
{
	// https://datatracker.ietf.org/doc/html/rfc768
	udp_header->dest = destport;  // destination port
	udp_header->source = srcprt;  // source port
	udp_header->len = htons(len); // packet length (including udp payload and udp header) in bytes
}

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		printf("Please write in the format \"mytraceroute <destination domain name>\"\n");
		exit(EXIT_FAILURE);
	}
	/**
	 * 1. The program first finds out the IP address
	 * corresponding to the given domain name
	 * (use gethostbyname())
	 */
	char IP[IP_BUF];
	IP[0] = 0;
	if (get_ip(argv[1], IP) < 0)
	{
		printf("Error in getting ip from the host \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("%s\n",IP);
	printf("%d\n",inet_addr(IP));

	// struct sockaddr_in client_addr;
	// client_addr.sin_addr.s_addr = inet_addr(IP);
	// client_addr.sin_family = AF_INET;
	// client_addr.sin_port = htons(DESTINATION_PORT);

	return 0;

}