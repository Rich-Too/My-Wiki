#!/bin/bash

commit_message=$(date +"%Y-%m-%d %H:%M:%S")

git add .
git commit -m "$commit_message"

git push
