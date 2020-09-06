# pam-delegated

Delegate SSH authentication to another (hopefully) secure service.

## Workflow

1. User authenticates w/ offered authentication method KeyboardInteractive
2. `pam-delegated` consults auth service to generate url that must be visited
    to authenticate this connection.
3. QR code to visit is generated and displayed.
4. User scans QR code with authorized device and visits URL. The service must be
    setup to only allow authorized users.
5. User presses `[enter]` and `pam-delegated` checks if the URL has been visited.

