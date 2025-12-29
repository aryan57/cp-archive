#!/bin/bash

# Configuration
REPO="aryan57/ubuntu-cpp-image"
DATE_TAG=$(date +%Y-%m-%d)

set -e

# Verify Dockerfile exists in current directory
if [ ! -f "Dockerfile" ]; then
    echo "❌ Error: Dockerfile not found in $(pwd)"
    exit 1
fi

echo "🛠️  Building image: $REPO..."
# The '.' is the context (current directory)
docker build -t $REPO:latest .

echo "🏷️  Tagging with date: $DATE_TAG..."
docker tag $REPO:latest $REPO:$DATE_TAG

echo "🚀 Pushing to Docker Hub..."
docker push $REPO:latest
docker push $REPO:$DATE_TAG

echo "✅ Success!"
