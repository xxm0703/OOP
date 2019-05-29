interface RateLimitable {

    /* Permits or rejects a call to the service.
     * @param service - the name/id of the service being called
     * @param now - the current time in milliseconds
     * @return false if the request is allowed or true in case it is rate-limited.
     */
    boolean shouldBlock(String service, long now);
}

interface RateLimitConfigable {

    /* Returns the size of the window in seconds in which the request are rate-limited. */
    long getTimeSpanSeconds();

    /* Returns the maximum number of allowed requests in one window. */
    int getAllowedRequests();
}


class RateLimiter implements RateLimitable, RateLimitConfigable {
    private final int allowedRequests;
    private final long timeSpan;
    private long remainingRequests, currentTime;

    public RateLimiter(int allowedRequests, int timeSpan) {
        this.allowedRequests = allowedRequests;
        this.timeSpan = timeSpan;

        remainingRequests = allowedRequests;
        currentTime = 0;
    }

    @Override
    public boolean shouldBlock(String service, long now) {
        if (currentTime == 0 || currentTime / getTimeSpanSeconds() > now) {
            remainingRequests = getAllowedRequests();
            currentTime = now;
        }

        if (remainingRequests > 0) {
            remainingRequests--;
            return false;
        }

        return true;
    }

    @Override
    public long getTimeSpanSeconds() {
        return timeSpan;
    }

    @Override
    public int getAllowedRequests() {
        return allowedRequests;
    }
}

public class Test {
    public static void main(String[] args) {
        RateLimiter test = new RateLimiter(5, 60000);
    }
}