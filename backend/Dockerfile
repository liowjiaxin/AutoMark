FROM docker:28.0.1-dind

WORKDIR /app

# Install dependencies for Pyenv and Python builds
RUN apk add --no-cache \
  bash curl git make gcc musl-dev libffi-dev \
  openssl-dev bzip2-dev readline-dev sqlite-dev \
  zlib-dev xz-dev tk-dev linux-headers

# Install Pyenv
ENV PYENV_ROOT="/root/.pyenv"
ENV PATH="$PYENV_ROOT/bin:$PYENV_ROOT/shims:$PATH"

# Use pyenv to install python 3.11
RUN git clone https://github.com/pyenv/pyenv.git $PYENV_ROOT && \
  echo 'eval "$(pyenv init --path)"' >> ~/.profile && \
  /bin/bash -c "source ~/.profile && pyenv install 3.11.6 && pyenv global 3.11.6"

# Install python dependencies
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# Copy over source files
COPY app .

# Add entrypoint for building docker image and start docker daemon
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
CMD ["uvicorn", "main:app", "--host", "0.0.0.0", "--port", "8000"]
