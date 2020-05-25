#!/usr/bin/env python3

# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

import os
from os.path import join, dirname
from jinja2 import Environment, FileSystemLoader, Template

template_path = join(dirname(__file__), "templates")
env = Environment(loader=FileSystemLoader(template_path))

protos_dir = join("uefi", "protos")
os.makedirs(protos_dir, exist_ok=True)

proto_template = env.get_template("proto.j2")

import yaml
protos = yaml.load(open("protos.yaml"))
for proto in protos:
    with open(os.path.join(protos_dir, proto["name"] + ".h"), 'w') as header:
        header.write(template.render(proto_template))
