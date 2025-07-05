package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

type Bot struct {
	Balance float64
	Position int // +ve for long, -ve for short
	EntryPrice float64
	ProfitLossHistory []float64
}

func (b *Bot) Buy(price float64, qty int) {
	cost := price * float64(qty)
	if b.Balance >= cost {
		b.Balance -= cost
		b.Position += qty
		b.EntryPrice = price
		fmt.Printf("Bought %d units at $%.2f each.\n", qty, price)
		b.recordProfitLoss(price)
	} else {
		fmt.Println("Not enough balance to buy.")
	}
}

func (b *Bot) Sell(price float64, qty int) {
	if b.Position >= qty {
		b.Balance += price * float64(qty)
		b.Position -= qty
		fmt.Printf("Sold %d units at $%.2f each.\n", qty, price)
		b.recordProfitLoss(price)
	} else {
		fmt.Println("Not enough position to sell.")
	}
}

func (b *Bot) recordProfitLoss(price float64) {
	// Calculate current profit/loss
	pl := b.Balance + float64(b.Position)*price - 10000.0
	b.ProfitLossHistory = append(b.ProfitLossHistory, pl)
}

func drawPriceChart(prices []float64) {
	if len(prices) == 0 {
		fmt.Println("No price history yet.")
		return
	}
	max := prices[0]
	min := prices[0]
	for _, p := range prices {
		if p > max {
			max = p
		}
		if p < min {
			min = p
		}
	}
	height := 10
	width := len(prices)
	scale := (max - min) / float64(height-1)
	if scale == 0 {
		scale = 1
	}
	chart := make([][]rune, height)
	for i := range chart {
		chart[i] = make([]rune, width)
		for j := range chart[i] {
			chart[i][j] = ' '
		}
	}
	for x, p := range prices {
		y := int((p - min) / scale)
		if y >= height {
			y = height - 1
		}
		chart[height-1-y][x] = '*'
	}
	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			fmt.Printf("%c", chart[i][j])
		}
		fmt.Println()
	}
	fmt.Printf("Min: %.2f  Max: %.2f\n", min, max)
}

func drawProfitLossChart(history []float64) {
	if len(history) == 0 {
		fmt.Println("No profit/loss history yet.")
		return
	}
	height := 10
	width := len(history)
	max := history[0]
	min := history[0]
	for _, v := range history {
		if v > max {
			max = v
		}
		if v < min {
			min = v
		}
	}
	scale := (max - min) / float64(height-1)
	if scale == 0 {
		scale = 1
	}
	chart := make([][]rune, height)
	for i := range chart {
		chart[i] = make([]rune, width)
		for j := range chart[i] {
			chart[i][j] = ' '
		}
	}
	for x, v := range history {
		y := int((v - min) / scale)
		if y >= height {
			y = height - 1
		}
		chart[height-1-y][x] = '#'
	}
	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			fmt.Printf("%c", chart[i][j])
		}
		fmt.Println()
	}
	fmt.Printf("P/L Min: %.2f  Max: %.2f\n", min, max)
}

func main() {
	rand.Seed(time.Now().UnixNano())
	bot := Bot{Balance: 10000.0, Position: 0, EntryPrice: 0.0, ProfitLossHistory: []float64{0}}
	price := 100.0
	priceHistory := []float64{price}
	reader := bufio.NewReader(os.Stdin)

	fmt.Println("Welcome to the Dummy Paper Trading Bot!")
	fmt.Println("You start with $10,000 paper money. Type 'help' for commands.")

	for {
		fmt.Printf("\nCurrent price: $%.2f | Balance: $%.2f | Position: %d\n", price, bot.Balance, bot.Position)
		fmt.Print("> ")
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		args := strings.Split(input, " ")

		if len(args) == 0 {
			continue
		}

		switch args[0] {
		case "buy":
			if len(args) < 2 {
				fmt.Println("Usage: buy <qty>")
				continue
			}
			qty, err := strconv.Atoi(args[1])
			if err != nil || qty <= 0 {
				fmt.Println("Invalid quantity.")
				continue
			}
			bot.Buy(price, qty)
			drawProfitLossChart(bot.ProfitLossHistory)
		case "sell":
			if len(args) < 2 {
				fmt.Println("Usage: sell <qty>")
				continue
			}
			qty, err := strconv.Atoi(args[1])
			if err != nil || qty <= 0 {
				fmt.Println("Invalid quantity.")
				continue
			}
			bot.Sell(price, qty)
			drawProfitLossChart(bot.ProfitLossHistory)
		case "next":
			// Simulate price change
			change := rand.Float64()*4 - 2 // -2 to +2
			price += change
			if price < 1 {
				price = 1
			}
			priceHistory = append(priceHistory, price)
			fmt.Printf("Price moved to $%.2f\n", price)
		case "chart":
			drawPriceChart(priceHistory)
		case "plchart":
			drawProfitLossChart(bot.ProfitLossHistory)
		case "status":
			fmt.Printf("Balance: $%.2f | Position: %d | Entry Price: $%.2f\n", bot.Balance, bot.Position, bot.EntryPrice)
		case "help":
			fmt.Println("Commands:")
			fmt.Println("  buy <qty>    - Buy <qty> units at current price")
			fmt.Println("  sell <qty>   - Sell <qty> units at current price")
			fmt.Println("  next         - Move to next time step (price changes)")
			fmt.Println("  chart        - Show price history chart")
			fmt.Println("  plchart      - Show profit/loss chart")
			fmt.Println("  status       - Show account status")
			fmt.Println("  help         - Show this help message")
			fmt.Println("  quit         - Exit the bot")
		case "quit":
			fmt.Println("Exiting. Final status:")
			fmt.Printf("Balance: $%.2f | Position: %d | Entry Price: $%.2f\n", bot.Balance, bot.Position, bot.EntryPrice)
			return
		default:
			fmt.Println("Unknown command. Type 'help' for a list of commands.")
		}
	}
}
