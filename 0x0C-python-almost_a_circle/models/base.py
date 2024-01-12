#!/usr/bin/python3
"""
This module implements `base` class of all other classes in this project.
"""


class Base:
    """
    implementation
    """

    __nb_objects = 0

    def __init__(self, id=None):
        """initialization
        Args:
            id (int, optional): object id. Defaults to None.
        """
        if id is not None:
            self.id = id
        else:
            Base.__nb_objects += 1
            self.id = Base.__nb_objects
