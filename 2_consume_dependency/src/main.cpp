// Source: https://zguide.zeromq.org/docs/chapter1/
//
//  Weather update server in C++
//  Binds PUB socket to tcp://*:5556
//  Publishes random weather updates
//
#include <zmq.hpp>

#include <cstdio>
#include <cstdlib>
#include <ctime>

#define within(num) (int) ((float) num * random () / (RAND_MAX + 1.0))

int main () {

    //  Prepare our context and publisher
    zmq::context_t context(1);
    zmq::socket_t publisher(context, zmq::socket_type::pub);
    publisher.bind("tcp://*:5556");

    //  Initialize random number generator
    srandom((unsigned) time (NULL));
    while (1) {

        int zipcode, temperature, relhumidity;

        //  Get values that will fool the boss
        zipcode     = within(100000);
        temperature = within(215) - 80;
        relhumidity = within(50) + 10;

        //  Send message to all subscribers
        zmq::message_t message(20);
        snprintf((char *) message.data(), 20, "%05d %d %d", zipcode, temperature, relhumidity);
        publisher.send(message, zmq::send_flags::none);

    }
    return 0;
}
