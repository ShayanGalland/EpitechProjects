FROM python:3.9.10-alpine
COPY requirements.txt /app/requirements.txt
RUN pip install -r /app/requirements.txt
WORKDIR /app
COPY . /app
EXPOSE 80
CMD [ "python3", "-m" , "flask", "run", "--host=0.0.0.0", "--port=80"]