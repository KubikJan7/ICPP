#ifndef ZPRAVA_PORT_H
#define ZPRAVA_PORT_H

struct ASitovyPrvek;

struct ZpravaPort {
public:
	Zprava* zprava;
	ASitovyPrvek* port;
	ZpravaPort() {}
	ZpravaPort(Zprava* zprava, ASitovyPrvek* port) : zprava(zprava), port(port) {}
};

#endif