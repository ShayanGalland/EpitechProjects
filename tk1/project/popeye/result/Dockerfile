FROM node:12.22.10-alpine3.15
WORKDIR /app
COPY package*.json ./
RUN npm install
COPY . .
EXPOSE 80
CMD [ "node", "server.js"]
