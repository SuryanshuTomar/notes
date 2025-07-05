import { QueryClient, QueryClientProvider } from '@tanstack/react-query'
import { trpc } from './lib/trpc'
import { httpBatchLink } from '@trpc/client'
import React from 'react'
import ReactDOM from 'react-dom/client'
import App from './App'
import './index.css'

const queryClient = new QueryClient();
const trpcClient = trpc.createClient({
  links: [httpBatchLink({
    url: "http://localhost:3000/trpc"
  })]
})
const TrpcProvider = trpc.Provider;

ReactDOM.createRoot(document.getElementById('root') as HTMLElement).render(
  <React.StrictMode>
    <TrpcProvider queryClient={queryClient} client={trpcClient}>
      <QueryClientProvider client={queryClient}>
        <App />
      </QueryClientProvider>
    </TrpcProvider>
  </React.StrictMode>,
)
