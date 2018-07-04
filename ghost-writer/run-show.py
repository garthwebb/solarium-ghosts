import argparse
import sys
import logging

from controller import Controller
# from server.server import run_server

LOG_FORMAT = '%(asctime)-15s | %(name)-12s (%(levelname)s): %(message)s'


def main():
    parser = argparse.ArgumentParser(description='Run solarium ghost')
    parser.add_argument(
        '--light-driver',
        dest='light_driver',
        default='solarium',
        help='Sets the lighting driver to use when writing LED data (default "solarium")'
    )
    parser.add_argument(
        '--blue-driver',
        dest='blue_driver',
        default='blue',
        help='Sets the lighting driver to use when writing LED data (default "blue")'
    )
    parser.add_argument(
        '--generator',
        dest='generator_name',
        default=None,
        help='Sets the LED generator to generate each frame of light data'
    )
    parser.add_argument(
        '--fps',
        dest='fps',
        default=None,
        help='Sets the fps for the show'
    )
    parser.add_argument(
        '--verbose',
        dest='verbose',
        action='store_true',
        help='Enable verbose logging'
    )
    # parser.add_argument(
    #     '--server_port',
    #     dest='server_port',
    #     type=int,
    #     help='Web server port; -1 to disable.'
    # )
    # parser.set_defaults(opc_input=True, server_port=1977)
    args = parser.parse_args()

    log_level = logging.DEBUG if args.verbose else logging.INFO
    logging.basicConfig(level=log_level, format=LOG_FORMAT)

    show = Controller()
    show.set_light_driver(args.light_driver, {})
    show.set_blue_driver(args.blue_driver, {})

    if args.generator_name:
        show.set_generator(args.generator_name)

    if args.fps:
        show.init_frame_rate(int(args.fps))

    # if args.server_port >= 0:
    #     run_server(show, port=args.server_port)

    try:
        show.run()
    except KeyboardInterrupt:
        sys.exit(0)


main()
